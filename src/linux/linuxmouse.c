#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/uinput.h>
#include "inputsim/mouse.h"
#include "key.h"
#include "uinputhelper.h"
#include "mouseimpl.h"
#include "mysleep.h"

static const int wait_MS = 10;
static int fd;

void sim_impl_ChangeMouseButtonState(unsigned int button, unsigned int state){
  /* conversion table from sim mousebuttons to unix mousebuttons */
  static const int buttons[SIM_MB_SIZE] = {[SIM_MB_LEFT] = BTN_LEFT,
					   [SIM_MB_RIGHT] = BTN_RIGHT,
					   [SIM_MB_MIDDLE] = BTN_MIDDLE};

  static const int states[SIM_KEYSTATE_SIZE] = {[SIM_KEYSTATE_UP] = 0,
						[SIM_KEYSTATE_DOWN] = 1};

  if (button < 0 || button > SIM_MB_SIZE || state < 0 || state > SIM_KEYSTATE_SIZE){
    return;
  }
  emit(fd, EV_KEY, buttons[button], states[state]);
  emit(fd, EV_SYN, SYN_REPORT, 0);
  mysleep_MS(wait_MS);
}

static void emit_rel(int fd, int rel, int a){
    emit(fd, EV_REL, rel, a);
    emit(fd, EV_SYN, SYN_REPORT, 0);
    mysleep_MS(wait_MS);  
}

void sim_impl_MouseMoveRel(int dx, int dy){
  static const int step = 3;
  
  int x_inc = (dx >= 0 ? step : -step);
  int y_inc = (dy >= 0 ? step : -step);
  for (int i = 0; i < dx/x_inc; ++i){
    emit_rel(fd, REL_X, x_inc);
  }
  for (int i = 0; i < dy/y_inc; ++i){
    emit_rel(fd, REL_Y, y_inc);
  }
  if (dx%x_inc){
    emit_rel(fd, REL_Y, dx%x_inc);
  }
  if (dy%y_inc){
    emit_rel(fd, REL_Y, dy%y_inc);
  }
}

void sim_impl_MouseMove(int x, int y){
  sim_impl_MouseMoveRel(-10000, -10000);
  sim_impl_MouseMoveRel(x, y);
	//mysleep_MS(1);
}

void sim_impl_MouseScroll(unsigned int direction, unsigned int by){
  static const int scroll[SIM_SCROLL_SIZE] = {[SIM_SCROLL_UP] = 1,
					      [SIM_SCROLL_DOWN] = -1};

  if (by < 1){
    return;
  }
  if (direction > SIM_SCROLL_SIZE){
    return;
  }
  emit(fd, EV_REL, REL_WHEEL, scroll[direction]);
  emit(fd, EV_SYN, SYN_REPORT, 0);
  mysleep_MS(wait_MS);
  return sim_impl_MouseScroll(direction, --by);
}

int sim_impl_MouseQuit(){
	destroy_virtual_device(fd);
	close(fd);
}
	
int sim_impl_MouseInit(){
	fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	if (fd == -1){
		return -1;	
	}
	ioctl(fd, UI_SET_EVBIT, EV_KEY);
	ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
	ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);
	ioctl(fd, UI_SET_KEYBIT, BTN_MIDDLE);
	
	ioctl(fd, UI_SET_EVBIT, EV_REL);
	ioctl(fd, UI_SET_RELBIT, REL_X);
	ioctl(fd, UI_SET_RELBIT, REL_Y);
	ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
	setup_virtual_device(fd, 0x1234, 0x5679, "INPUTSIM Mouse device");
	return 0;
}
