#ifndef KEYBOARDIMPL_H_
#define KEYBOARDIMPL_H_

#include <wchar.h>
#include <stdint.h>

int sim_impl_KBInit();
int sim_impl_KBQuit();
void sim_impl_KBChangeButtonStateA(char c, unsigned int state);
void sim_impl_KBChangeButtonStateW(wchar_t wc, unsigned int state);
void sim_impl_KBChangeButtonStateScancode(unsigned int scancode, unsigned int state);

#endif
