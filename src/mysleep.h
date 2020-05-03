#ifndef MYSLEEP_H_
#define MYSLEEP_H_

#if defined (_WIN32)
	#include <windows.h>
	static void mysleep(int milliseconds){
		Sleep(milliseconds);
	}
#elif defined(__unix)
	#include <time.h>
        #include <errno.h>
	static void mysleep_ns(long nanoseconds){
		struct timespec delay;
		delay.tv_sec = nanoseconds / (1000 * 1000 * 1000); 
		delay.tv_nsec = nanoseconds % (1000 * 1000 * 1000);
		while (nanosleep(&delay, &delay) != 0 && errno == EINTR);
	}
	static void mysleep_MS(long microseconds){
	  mysleep_ns(microseconds * 1000);
	}
	static void mysleep(long milliseconds){
	  mysleep_ns(milliseconds * 1000 * 1000);
	}

#endif

#endif /* MYSLEEP_H_ */
