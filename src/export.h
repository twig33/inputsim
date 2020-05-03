#ifndef EXPORT_H_
#define EXPORT_H_

#if defined(WIN32)
	#define EXPORT __declspec(dllexport)
#elif defined(__unix)
	#define EXPORT __attribute__((visibility("default")))
#endif

#endif
