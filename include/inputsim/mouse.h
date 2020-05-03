#ifndef MOUSE_H_
#define MOUSE_H_

	enum {
		SIM_MB_LEFT,
		SIM_MB_RIGHT,
		SIM_MB_MIDDLE,
		SIM_MB_SIZE
	};
	enum {
		SIM_SCROLL_DOWN,
		SIM_SCROLL_UP,
		SIM_SCROLL_SIZE
	};
	void sim_MouseScroll (int direction, int by);
	void sim_MousePress (int button);
	void sim_MouseRelease (int button);
	void sim_MouseClick (int button);
	void sim_MouseClickAt (int button, int x, int y);
	void sim_MouseMove (int x, int y);

#endif