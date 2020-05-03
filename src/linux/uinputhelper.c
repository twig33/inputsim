#include "uinputhelper.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <linux/uinput.h>
#include <fcntl.h>
#include "mysleep.h"

void emit(int fd, int type, int code, int val)
{
   struct input_event ie;

   ie.type = type;
   ie.code = code;
   ie.value = val;
   ie.time.tv_sec = 0;
   ie.time.tv_usec = 0;

   ssize_t w = write(fd, &ie, sizeof(ie));
}

void setup_virtual_device(int fd, uint16_t vendor, uint16_t product, const char *name) {
	struct uinput_setup usetup;

	memset(&usetup, 0, sizeof(usetup));
	usetup.id.bustype = BUS_USB;
	usetup.id.vendor = vendor;
	usetup.id.product = product;
	strcpy(usetup.name, name);

	ioctl(fd, UI_DEV_SETUP, &usetup);
	ioctl(fd, UI_DEV_CREATE);
	mysleep(1);
}

void destroy_virtual_device(int fd){
	ioctl(fd, UI_DEV_DESTROY);
}
