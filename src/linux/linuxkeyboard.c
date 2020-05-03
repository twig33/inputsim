#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "inputsim/keyboard.h"
#include "keyboardimpl.h"
#include "uinputhelper.h"
#include "key.h"
#include "../mysleep.h"

static int fd;

/* Pick a scancode no keyboard ever uses,
 * so if the program couldn't cleanup properly,
 * hopefully the user doesn't notice that a key
 * is bound to an unusual character. */
static const int scancode = 237; 
static char initial_keycode_xmodmap[255]; // Stores the initial binding of the keycode in xmodmap so we can restore it

static int keystate_unixval(unsigned int sim_keystate){
  static const int keystates[SIM_KEYSTATE_SIZE] = {[SIM_KEYSTATE_DOWN] = 1,
						   [SIM_KEYSTATE_UP] = 0};
  if (sim_keystate > SIM_KEYSTATE_SIZE){
    return -1;
  }
  return keystates[sim_keystate];
}

static void set_keycode_xmodmap(const unsigned int keycode, const char* to){
  static char keycode_str[10];
  sprintf(keycode_str, "%d", keycode);
  static char expr[100];
  strcpy(expr, "xmodmap -e \"keycode ");
  strcat(expr, keycode_str);
  strcat(expr, " = ");
  strcat(expr, to);
  strcat(expr, "\"");
  system(expr);  
}

void sim_impl_KBChangeButtonStateScancode(unsigned int scancode, unsigned int state){
  emit(fd, EV_KEY, scancode, keystate_unixval(state));
  emit(fd, EV_SYN, SYN_REPORT, 0);
  mysleep_MS(10);
}

void sim_impl_KBChangeButtonStateA(char c, unsigned int state){
  /* Make a keycode correspond to the character we need */
  static char decimal[4];
  sprintf(decimal, "%d", (unsigned int)c);
  set_keycode_xmodmap(scancode+8, decimal);
  /* Then change the state of the button by the scancode */
  sim_impl_KBChangeButtonStateScancode(scancode, state);
}  

void sim_impl_KBChangeButtonStateW(wchar_t wc, unsigned int state){
  /* Make a keycode correspond to the character we need */
  static char hex[6];
  hex[0] = 'U';
  sprintf(hex+1, "%x", wc);
  set_keycode_xmodmap(scancode+8, hex);
  mysleep_MS(10);
  /* Then change the state of the button by the scancode */
  sim_impl_KBChangeButtonStateScancode(scancode, state);
}

int sim_impl_KBQuit(){
  destroy_virtual_device(fd);
  static char command[255];
  /* Reset the state of the keycode */
  strcpy(command, "xmodmap -e \"");
  strcat(command, initial_keycode_xmodmap);
  strcat(command, "\"");
  system(command);
  close(fd);
}

void sig_handler(int sig){
  if (sig == SIGTERM){
    /* Cleanup */
    sim_impl_KBQuit();
  }
}

int sim_impl_KBInit(){
  struct sigaction action;
  memset(&action, 0, sizeof(action));
  action.sa_handler = sig_handler;
  sigaction(SIGTERM, &action, NULL);
  
  fd = open("/dev/uinput", O_WRONLY  | O_NONBLOCK);
  ioctl(fd, UI_SET_EVBIT, EV_KEY);
  ioctl(fd, UI_SET_KEYBIT, scancode);
  setup_virtual_device(fd, 0x1234, 0x5678, "INPUTSIM Keyboard device");

  /* Run command to get the initial state of the keycode */
  FILE *fp;
  static char command[255];
  strcpy(command, "xmodmap -pke | grep \"keycode ");
  static char keycode_str[10];
  sprintf(keycode_str, "%d", scancode+8);
  strcat(command, keycode_str);
  strcat(command, " =\"");
  fp = popen(command, "r");
  if (fp == NULL){
    return -1;
  }
  if (fgets(initial_keycode_xmodmap, sizeof(initial_keycode_xmodmap), fp) == NULL){
    return -1;
  }
  pclose(fp);
  return 0;
}


