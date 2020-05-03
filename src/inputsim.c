#include "inputsim/inputsim.h"
#include "mouseimpl.h"
#include "export.h"
#include "keyboardimpl.h"

EXPORT int sim_init(){
	return sim_impl_MouseInit() | sim_impl_KBInit();
}

EXPORT int sim_quit(){
	return sim_impl_MouseQuit() | sim_impl_KBQuit();	
}