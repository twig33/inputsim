#include <string.h>

#include <stdint.h>
#include <wchar.h>
#include "export.h"
#include "key.h"
#include "keyboardimpl.h"
#include "inputsim/keyboard.h"

EXPORT void sim_KBPressA(char key){
	sim_impl_KBChangeButtonStateA(key, SIM_KEYSTATE_DOWN);
}

EXPORT void sim_KBReleaseA(char key){
	sim_impl_KBChangeButtonStateA(key, SIM_KEYSTATE_UP);
}

EXPORT void sim_KBClickA(char key){
	sim_KBPressA(key);
	sim_KBReleaseA(key);
}

EXPORT void sim_KBInputStringA(const char *str){
	for (int i = 0; i < strlen(str); ++i){
		sim_KBClickA(str[i]);
	}
}

EXPORT void sim_KBPressW(wchar_t wkey){
	sim_impl_KBChangeButtonStateW(wkey, SIM_KEYSTATE_DOWN);
}

EXPORT void sim_KBReleaseW(wchar_t wkey){
	sim_impl_KBChangeButtonStateW(wkey, SIM_KEYSTATE_UP);
}

EXPORT void sim_KBClickW(wchar_t wkey){
	sim_KBPressW(wkey);
	sim_KBReleaseW(wkey);
}

EXPORT void sim_KBInputStringW(const wchar_t *wstr){
  for (int i = 0; i < wcslen(wstr); ++i){
    sim_KBClickW(wstr[i]);
  }
}

EXPORT void sim_KBPressScancode(uint16_t scancode){
	sim_impl_KBChangeButtonStateScancode(scancode, SIM_KEYSTATE_DOWN);
}

EXPORT void sim_KBReleaseScancode(uint16_t scancode){
	sim_impl_KBChangeButtonStateScancode(scancode, SIM_KEYSTATE_UP);
}

EXPORT void sim_KBClickScancode(uint16_t scancode){
	sim_KBPressScancode(scancode);
	sim_KBReleaseScancode(scancode);
}
