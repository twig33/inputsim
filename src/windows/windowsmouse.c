#include <windows.h>
#include "inputsim/mouse.h"
#include "mouseimpl.h"
#include "key.h"
#include "mysleep.h"
	
static const DWORD buttonFlags[SIM_MB_SIZE][SIM_KEYSTATE_SIZE] =
  {{MOUSEEVENTF_LEFTUP, MOUSEEVENTF_LEFTDOWN},
   {MOUSEEVENTF_RIGHTUP, MOUSEEVENTF_RIGHTDOWN},
   {MOUSEEVENTF_MIDDLEUP, MOUSEEVENTF_MIDDLEDOWN}};

static void TransformCoordinates(int *x, int *y){
  static double pX = -1;
  static double pY = -1;
  if (pX == -1 && pY == -1){
    HDC screen = GetDC(NULL);
    int w = GetDeviceCaps(screen, HORZRES);
    int h = GetDeviceCaps(screen, VERTRES);
    ReleaseDC(NULL, screen);
    pX = 65535.0 / w;
    pY = 65535.0 / h;
  }
  *x *= pX;
  *y *= pY;
}

int sim_impl_MouseInit(){
	return 0;
}

int sim_impl_MouseQuit(){
	return 0;	
}

void sim_impl_ChangeMouseButtonState(unsigned int button, unsigned int state){
  INPUT input;
  input.type = INPUT_MOUSE;
  input.mi.dwFlags = buttonFlags[button][state] | MOUSEEVENTF_ABSOLUTE;
  SendInput(1, &input, sizeof(input));
}
	
void sim_impl_MouseMove(int x, int y){
  TransformCoordinates(&x, &y);
  INPUT input;
  input.type = INPUT_MOUSE;
  input.mi.dx = x;
  input.mi.dy = y;
  input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
  SendInput(1, &input, sizeof(input));
}
	
void sim_impl_MouseScroll(unsigned int direction, unsigned int by){
  INPUT input;
  input.type = INPUT_MOUSE;
  input.mi.dwFlags = MOUSEEVENTF_WHEEL;
  input.mi.mouseData = WHEEL_DELTA * direction * by;
  SendInput(1, &input, sizeof(input));
}
	
/*void sim_MousePress(int button){
  ChangeButtonState(button, SIM_MBSTATE_DOWN);
}
	
void sim_MouseRelease(int button){
  ChangeButtonState(button, SIM_MBSTATE_UP);
}
	
void sim_MouseClick(int button){
  sim_MousePress(button);
  mysleep(wait_ms);
  sim_MouseRelease(button);
}
	
void sim_MouseClickAt(int button, int x, int y){
  sim_MouseMove(x, y);
  sim_MouseClick(button);
}*/
