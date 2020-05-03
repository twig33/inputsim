#ifndef SIM_KEYBOARD_H_
#define SIM_KEYBOARD_H_

#include <stdint.h>
#include <wchar.h>

#if defined(UNICODE)
#define __INPUTSIM_NAME_AW(func) func##W
#else
#define __INPUTSIM_NAME_AW(func) func##A
#endif

//from uinput
//Some may not work on windows
#define SIM_KEY_RESERVED		0
#define SIM_KEY_ESC			1
#define SIM_KEY_1			2
#define SIM_KEY_2			3
#define SIM_KEY_3			4
#define SIM_KEY_4			5
#define SIM_KEY_5			6
#define SIM_KEY_6			7
#define SIM_KEY_7			8
#define SIM_KEY_8			9
#define SIM_KEY_9			10
#define SIM_KEY_0			11
#define SIM_KEY_MINUS		12
#define SIM_KEY_EQUAL		13
#define SIM_KEY_BACKSPACE		14
#define SIM_KEY_TAB			15
#define SIM_KEY_Q			16
#define SIM_KEY_W			17
#define SIM_KEY_E			18
#define SIM_KEY_R			19
#define SIM_KEY_T			20
#define SIM_KEY_Y			21
#define SIM_KEY_U			22
#define SIM_KEY_I			23
#define SIM_KEY_O			24
#define SIM_KEY_P			25
#define SIM_KEY_LEFTBRACE		26
#define SIM_KEY_RIGHTBRACE		27
#define SIM_KEY_ENTER		28
#define SIM_KEY_LEFTCTRL		29
#define SIM_KEY_A			30
#define SIM_KEY_S			31
#define SIM_KEY_D			32
#define SIM_KEY_F			33
#define SIM_KEY_G			34
#define SIM_KEY_H			35
#define SIM_KEY_J			36
#define SIM_KEY_K			37
#define SIM_KEY_L			38
#define SIM_KEY_SEMICOLON		39
#define SIM_KEY_APOSTROPHE		40
#define SIM_KEY_GRAVE		41
#define SIM_KEY_LEFTSHIFT		42
#define SIM_KEY_BACKSLASH		43
#define SIM_KEY_Z			44
#define SIM_KEY_X			45
#define SIM_KEY_C			46
#define SIM_KEY_V			47
#define SIM_KEY_B			48
#define SIM_KEY_N			49
#define SIM_KEY_M			50
#define SIM_KEY_COMMA		51
#define SIM_KEY_DOT			52
#define SIM_KEY_SLASH		53
#define SIM_KEY_RIGHTSHIFT		54
#define SIM_KEY_KPASTERISK		55
#define SIM_KEY_LEFTALT		56
#define SIM_KEY_SPACE		57
#define SIM_KEY_CAPSLOCK		58
#define SIM_KEY_F1			59
#define SIM_KEY_F2			60
#define SIM_KEY_F3			61
#define SIM_KEY_F4			62
#define SIM_KEY_F5			63
#define SIM_KEY_F6			64
#define SIM_KEY_F7			65
#define SIM_KEY_F8			66
#define SIM_KEY_F9			67
#define SIM_KEY_F10			68
#define SIM_KEY_NUMLOCK		69
#define SIM_KEY_SCROLLLOCK		70
#define SIM_KEY_KP7			71
#define SIM_KEY_KP8			72
#define SIM_KEY_KP9			73
#define SIM_KEY_KPMINUS		74
#define SIM_KEY_KP4			75
#define SIM_KEY_KP5			76
#define SIM_KEY_KP6			77
#define SIM_KEY_KPPLUS		78
#define SIM_KEY_KP1			79
#define SIM_KEY_KP2			80
#define SIM_KEY_KP3			81
#define SIM_KEY_KP0			82
#define SIM_KEY_KPDOT		83

#define SIM_KEY_ZENKAKUHANKAKU	85
#define SIM_KEY_102ND		86
#define SIM_KEY_F11			87
#define SIM_KEY_F12			88
#define SIM_KEY_RO			89
#define SIM_KEY_KATAKANA		90
#define SIM_KEY_HIRAGANA		91
#define SIM_KEY_HENKAN		92
#define SIM_KEY_KATAKANAHIRAGANA	93
#define SIM_KEY_MUHENKAN		94
#define SIM_KEY_KPJPCOMMA		95
#define SIM_KEY_KPENTER		96
#define SIM_KEY_RIGHTCTRL		97
#define SIM_KEY_KPSLASH		98
#define SIM_KEY_SYSRQ		99
#define SIM_KEY_RIGHTALT		100
#define SIM_KEY_LINEFEED		101
#define SIM_KEY_HOME		102
#define SIM_KEY_UP			103
#define SIM_KEY_PAGEUP		104
#define SIM_KEY_LEFT		105
#define SIM_KEY_RIGHT		106
#define SIM_KEY_END			107
#define SIM_KEY_DOWN		108
#define SIM_KEY_PAGEDOWN		109
#define SIM_KEY_INSERT		110
#define SIM_KEY_DELETE		111
#define SIM_KEY_MACRO		112
#define SIM_KEY_MUTE		113
#define SIM_KEY_VOLUMEDOWN		114
#define SIM_KEY_VOLUMEUP		115
#define SIM_KEY_POWER		116	/* SC System Power Down */
#define SIM_KEY_KPEQUAL		117
#define SIM_KEY_KPPLUSMINUS		118
#define SIM_KEY_PAUSE		119
#define SIM_KEY_SCALE		120	/* AL Compiz Scale (Expose) */

#define SIM_KEY_KPCOMMA		121
#define SIM_KEY_HANGEUL		122
#define SIM_KEY_HANGUEL		SIM_KEY_HANGEUL
#define SIM_KEY_HANJA		123
#define SIM_KEY_YEN			124
#define SIM_KEY_LEFTMETA		125
#define SIM_KEY_RIGHTMETA		126
#define SIM_KEY_COMPOSE		127

#define SIM_KEY_STOP		128	/* AC Stop */
#define SIM_KEY_AGAIN		129
#define SIM_KEY_PROPS		130	/* AC Properties */
#define SIM_KEY_UNDO		131	/* AC Undo */
#define SIM_KEY_FRONT		132
#define SIM_KEY_COPY		133	/* AC Copy */
#define SIM_KEY_OPEN		134	/* AC Open */
#define SIM_KEY_PASTE		135	/* AC Paste */
#define SIM_KEY_FIND		136	/* AC Search */
#define SIM_KEY_CUT			137	/* AC Cut */
#define SIM_KEY_HELP		138	/* AL Integrated Help Center */
#define SIM_KEY_MENU		139	/* Menu (show menu) */
#define SIM_KEY_CALC		140	/* AL Calculator */
#define SIM_KEY_SETUP		141
#define SIM_KEY_SLEEP		142	/* SC System Sleep */
#define SIM_KEY_WAKEUP		143	/* System Wake Up */
#define SIM_KEY_FILE		144	/* AL Local Machine Browser */
#define SIM_KEY_SENDFILE		145
#define SIM_KEY_DELETEFILE		146
#define SIM_KEY_XFER		147
#define SIM_KEY_PROG1		148
#define SIM_KEY_PROG2		149
#define SIM_KEY_WWW			150	/* AL Internet Browser */
#define SIM_KEY_MSDOS		151
#define SIM_KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
#define SIM_KEY_SCREENLOCK		SIM_KEY_COFFEE
#define SIM_KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
#define SIM_KEY_DIRECTION		SIM_KEY_ROTATE_DISPLAY
#define SIM_KEY_CYCLEWINDOWS	154
#define SIM_KEY_MAIL		155
#define SIM_KEY_BOOKMARKS		156	/* AC Bookmarks */
#define SIM_KEY_COMPUTER		157
#define SIM_KEY_BACK		158	/* AC Back */
#define SIM_KEY_FORWARD		159	/* AC Forward */
#define SIM_KEY_CLOSECD		160
#define SIM_KEY_EJECTCD		161
#define SIM_KEY_EJECTCLOSECD	162
#define SIM_KEY_NEXTSONG		163
#define SIM_KEY_PLAYPAUSE		164
#define SIM_KEY_PREVIOUSSONG	165
#define SIM_KEY_STOPCD		166
#define SIM_KEY_RECORD		167
#define SIM_KEY_REWIND		168
#define SIM_KEY_PHONE		169	/* Media Select Telephone */
#define SIM_KEY_ISO			170
#define SIM_KEY_CONFIG		171	/* AL Consumer Control Configuration */
#define SIM_KEY_HOMEPAGE		172	/* AC Home */
#define SIM_KEY_REFRESH		173	/* AC Refresh */
#define SIM_KEY_EXIT		174	/* AC Exit */
#define SIM_KEY_MOVE		175
#define SIM_KEY_EDIT		176
#define SIM_KEY_SCROLLUP		177
#define SIM_KEY_SCROLLDOWN		178
#define SIM_KEY_KPLEFTPAREN		179
#define SIM_KEY_KPRIGHTPAREN	180
#define SIM_KEY_NEW			181	/* AC New */
#define SIM_KEY_REDO		182	/* AC Redo/Repeat */

#define SIM_KEY_F13			183
#define SIM_KEY_F14			184
#define SIM_KEY_F15			185
#define SIM_KEY_F16			186
#define SIM_KEY_F17			187
#define SIM_KEY_F18			188
#define SIM_KEY_F19			189
#define SIM_KEY_F20			190
#define SIM_KEY_F21			191
#define SIM_KEY_F22			192
#define SIM_KEY_F23			193
#define SIM_KEY_F24			194

#define SIM_KEY_PLAYCD		200
#define SIM_KEY_PAUSECD		201
#define SIM_KEY_PROG3		202
#define SIM_KEY_PROG4		203
#define SIM_KEY_DASHBOARD		204	/* AL Dashboard */
#define SIM_KEY_SUSPEND		205
#define SIM_KEY_CLOSE		206	/* AC Close */
#define SIM_KEY_PLAY		207
#define SIM_KEY_FASTFORWARD		208
#define SIM_KEY_BASSBOOST		209
#define SIM_KEY_PRINT		210	/* AC Print */
#define SIM_KEY_HP			211
#define SIM_KEY_CAMERA		212
#define SIM_KEY_SOUND		213
#define SIM_KEY_QUESTION		214
#define SIM_KEY_EMAIL		215
#define SIM_KEY_CHAT		216
#define SIM_KEY_SEARCH		217
#define SIM_KEY_CONNECT		218
#define SIM_KEY_FINANCE		219	/* AL Checkbook/Finance */
#define SIM_KEY_SPORT		220
#define SIM_KEY_SHOP		221
#define SIM_KEY_ALTERASE		222
#define SIM_KEY_CANCEL		223	/* AC Cancel */
#define SIM_KEY_BRIGHTNESSDOWN	224
#define SIM_KEY_BRIGHTNESSUP	225
#define SIM_KEY_MEDIA		226

#define SIM_KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
					   outputs (Monitor/LCD/TV-out/etc) */
#define SIM_KEY_KBDILLUMTOGGLE	228
#define SIM_KEY_KBDILLUMDOWN	229
#define SIM_KEY_KBDILLUMUP		230

#define SIM_KEY_SEND		231	/* AC Send */
#define SIM_KEY_REPLY		232	/* AC Reply */
#define SIM_KEY_FORWARDMAIL		233	/* AC Forward Msg */
#define SIM_KEY_SAVE		234	/* AC Save */
#define SIM_KEY_DOCUMENTS		235

#define SIM_KEY_BATTERY		236

#define SIM_KEY_BLUETOOTH		237
#define SIM_KEY_WLAN		238
#define SIM_KEY_UWB			239

#define SIM_KEY_UNKNOWN		240

#define SIM_KEY_VIDEO_NEXT		241	/* drive next video source */
#define SIM_KEY_VIDEO_PREV		242	/* drive previous video source */
#define SIM_KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
#define SIM_KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
					  brightness control is off,
					  rely on ambient */
#define SIM_KEY_BRIGHTNESS_ZERO	SIM_KEY_BRIGHTNESS_AUTO
#define SIM_KEY_DISPLAY_OFF		245	/* display device to off state */

#define SIM_KEY_WWAN		246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
#define SIM_KEY_WIMAX		SIM_KEY_WWAN
#define SIM_KEY_RFKILL		247	/* SIM_KEY that controls all radios */

#define SIM_KEY_MICMUTE		248	/* Mute / unmute the microphone */
#define SIM_KEY_SIZE (SIM_KEY_MICMUTE+1)

#define sim_KBPress __INPUTSIM_NAME_AW(sim_KBPress)
#define sim_KBRelease __INPUTSIM_NAME_AW(sim_KBRelease)
#define sim_KBClick __INPUTSIM_NAME_AW(sim_KBClick)
#define sim_KBInputString __INPUTSIM_NAME_AW(sim_KBInputString)

void sim_KBPressA(char key);
void sim_KBReleaseA(char key);
void sim_KBClickA(char key);
void sim_KBInputStringA(const char *str);

void sim_KBPressW(wchar_t wkey);
void sim_KBReleaseW(wchar_t wkey);
void sim_KBClickW(wchar_t wkey);
void sim_KBInputStringW(const wchar_t *wstr);

void sim_KBPressScancode(uint16_t scancode);
void sim_KBReleaseScancode(uint16_t scancode);
void sim_KBClickScancode(uint16_t scancode);

#endif
