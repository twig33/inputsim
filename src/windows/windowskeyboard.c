#include <windows.h>
#include <string.h>
#include <wchar.h>

#include "key.h"
#include "mysleep.h"
#include "inputsim/keyboard.h"

WORD keyStateFlags[SIM_KEYSTATE_SIZE] = {KEYEVENTF_KEYUP, 0};
	
static void ChangeButtonState (WORD wVk, WORD wScan, DWORD flags){
  INPUT input;
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = wVk;
  input.ki.wScan = wScan;
  input.ki.dwFlags = flags;
  SendInput(1, &input, sizeof(input));
}

int sim_impl_KBInit(){
	return 0;
}

int sim_impl_KBQuit(){
	return 0;	
}

void sim_impl_KBChangeButtonStateW(wchar_t wc, int state){
	ChangeButtonState(0, wc, KEYEVENTF_UNICODE | keyStateFlags[state]);
}

void sim_impl_KBChangeButtonStateA(char c, int state){
	sim_impl_KBChangeButtonStateW((wchar_t)c, state);
}

void sim_impl_KBChangeButtonStateScancode(int scancode, int state){
	ChangeButtonState(0, scancode, KEYEVENTF_SCANCODE | keyStateFlags[state]);
}
