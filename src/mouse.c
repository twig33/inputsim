#include "inputsim/mouse.h"
#include "key.h"
#include "mouseimpl.h"
#include "export.h"
#include "mysleep.h"

static int waitms = 10;

EXPORT void sim_MouseScroll (int direction, int by){
	sim_impl_MouseScroll(direction, by);
}

EXPORT void sim_MousePress (int button){
	sim_impl_ChangeMouseButtonState(button, SIM_KEYSTATE_DOWN);
}

EXPORT void sim_MouseRelease (int button){
	sim_impl_ChangeMouseButtonState(button, SIM_KEYSTATE_UP);
}

EXPORT void sim_MouseClick (int button){
	sim_MousePress(button);
	mysleep(waitms);
	sim_MouseRelease(button);
}

EXPORT void sim_MouseMove (int x, int y){
	sim_impl_MouseMove(x, y);
}

EXPORT void sim_MouseClickAt (int button, int x, int y){
	sim_MouseMove(x, y);
	mysleep(waitms);
	sim_MouseClick(button);
}