#ifndef UINPUTHELPER_H_
#define UINPUTHELPER_H_

#include <linux/uinput.h>
#include <stdint.h>

void emit(int fd, int type, int code, int val);
//void enable_key(int fd, uint16_t key);
//void enable_event(int fd, uint16_t ev);
//void enable_relative(int fd, uint16_t rel);
void setup_virtual_device(int fd, uint16_t vendor, uint16_t product, const char *name);
void destroy_virtual_device(int fd);

#endif
