#ifndef MOUSEIMPL_H_
#define MOUSEIMPL_H_

int sim_impl_MouseInit();
int sim_impl_MouseQuit();
void sim_impl_ChangeMouseButtonState(unsigned int button, unsigned int state);
void sim_impl_MouseMove(int x, int y);
void sim_impl_MouseMoveRel(int dx, int dy);
void sim_impl_MouseScroll(unsigned int direction, unsigned int by);

#endif
