#pragma once

#include <SDL.h>
#include <vector>
#include <stdint.h>

namespace sonic {

	enum class keyboard {
		key_0 = SDL_SCANCODE_0,
		key_1 = SDL_SCANCODE_1,
		key_2 = SDL_SCANCODE_2,
		key_3 = SDL_SCANCODE_3,
		key_4 = SDL_SCANCODE_4,
		key_5 = SDL_SCANCODE_5,
		key_6 = SDL_SCANCODE_6,
		key_7 = SDL_SCANCODE_7,
		key_8 = SDL_SCANCODE_8,
		key_9 = SDL_SCANCODE_9,
		key_a = SDL_SCANCODE_A,
		key_AC_BACK = SDL_SCANCODE_AC_BACK,
		key_AC_BOOKMARKS = SDL_SCANCODE_AC_BOOKMARKS,
		key_AC_FORWARD = SDL_SCANCODE_AC_FORWARD,
		key_AC_HOME = SDL_SCANCODE_AC_HOME,
		key_AC_REFRESH = SDL_SCANCODE_AC_REFRESH,
		key_AC_SEARCH = SDL_SCANCODE_AC_SEARCH,
		key_AC_STOP = SDL_SCANCODE_AC_STOP,
		key_AGAIN = SDL_SCANCODE_AGAIN,
		key_ALTERASE = SDL_SCANCODE_ALTERASE,
		key_QUOTE = SDL_SCANCODE_APOSTROPHE,
		key_APPLICATION = SDL_SCANCODE_APPLICATION,
		key_AUDIOMUTE = SDL_SCANCODE_AUDIOMUTE,
		key_AUDIONEXT = SDL_SCANCODE_AUDIONEXT,
		key_AUDIOPLAY = SDL_SCANCODE_AUDIOPLAY,
		key_AUDIOPREV = SDL_SCANCODE_AUDIOPREV,
		key_AUDIOSTOP = SDL_SCANCODE_AUDIOSTOP,
		key_b = SDL_SCANCODE_B,
		key_BACKSLASH = SDL_SCANCODE_BACKSLASH,
		key_BACKSPACE = SDL_SCANCODE_BACKSPACE,
		key_BRIGHTNESSDOWN = SDL_SCANCODE_BRIGHTNESSDOWN,
		key_BRIGHTNESSUP = SDL_SCANCODE_BRIGHTNESSUP,
		key_c = SDL_SCANCODE_C,
		key_CALCULATOR = SDL_SCANCODE_CALCULATOR,
		key_CANCEL = SDL_SCANCODE_CANCEL,
		key_CAPSLOCK = SDL_SCANCODE_CAPSLOCK,
		key_CLEAR = SDL_SCANCODE_CLEAR,
		key_CLEARAGAIN = SDL_SCANCODE_CLEARAGAIN,
		key_COMMA = SDL_SCANCODE_COMMA,
		key_COMPUTER = SDL_SCANCODE_COMPUTER,
		key_COPY = SDL_SCANCODE_COPY,
		key_CRSEL = SDL_SCANCODE_CRSEL,
		key_CURRENCYSUBUNIT = SDL_SCANCODE_CURRENCYSUBUNIT,
		key_CURRENCYUNIT = SDL_SCANCODE_CURRENCYUNIT,
		key_CUT = SDL_SCANCODE_CUT,
		key_d = SDL_SCANCODE_D,
		key_DECIMALSEPARATOR = SDL_SCANCODE_DECIMALSEPARATOR,
		key_DELETE = SDL_SCANCODE_DELETE,
		key_DISPLAYSWITCH = SDL_SCANCODE_DISPLAYSWITCH,
		key_DOWN = SDL_SCANCODE_DOWN,
		key_e = SDL_SCANCODE_E,
		key_EJECT = SDL_SCANCODE_EJECT,
		key_END = SDL_SCANCODE_END,
		key_EQUALS = SDL_SCANCODE_EQUALS,
		key_ESCAPE = SDL_SCANCODE_ESCAPE,
		key_EXECUTE = SDL_SCANCODE_EXECUTE,
		key_EXSEL = SDL_SCANCODE_EXSEL,
		key_f = SDL_SCANCODE_F,
		key_F1 = SDL_SCANCODE_F1,
		key_F10 = SDL_SCANCODE_F10,
		key_F11 = SDL_SCANCODE_F11,
		key_F12 = SDL_SCANCODE_F12,
		key_F13 = SDL_SCANCODE_F13,
		key_F14 = SDL_SCANCODE_F14,
		key_F15 = SDL_SCANCODE_F15,
		key_F16 = SDL_SCANCODE_F16,
		key_F17 = SDL_SCANCODE_F17,
		key_F18 = SDL_SCANCODE_F18,
		key_F19 = SDL_SCANCODE_F19,
		key_F2 = SDL_SCANCODE_F2,
		key_F20 = SDL_SCANCODE_F20,
		key_F21 = SDL_SCANCODE_F21,
		key_F22 = SDL_SCANCODE_F22,
		key_F23 = SDL_SCANCODE_F23,
		key_F24 = SDL_SCANCODE_F24,
		key_F3 = SDL_SCANCODE_F3,
		key_F4 = SDL_SCANCODE_F4,
		key_F5 = SDL_SCANCODE_F5,
		key_F6 = SDL_SCANCODE_F6,
		key_F7 = SDL_SCANCODE_F7,
		key_F8 = SDL_SCANCODE_F8,
		key_F9 = SDL_SCANCODE_F9,
		key_FIND = SDL_SCANCODE_FIND,
		key_g = SDL_SCANCODE_G,
		key_BACKQUOTE = SDL_SCANCODE_GRAVE,
		key_h = SDL_SCANCODE_H,
		key_HELP = SDL_SCANCODE_HELP,
		key_HOME = SDL_SCANCODE_HOME,
		key_i = SDL_SCANCODE_I,
		key_INSERT = SDL_SCANCODE_INSERT,
		key_j = SDL_SCANCODE_J,
		key_k = SDL_SCANCODE_K,
		key_KBDILLUMDOWN = SDL_SCANCODE_KBDILLUMDOWN,
		key_KBDILLUMTOGGLE = SDL_SCANCODE_KBDILLUMTOGGLE,
		key_KBDILLUMUP = SDL_SCANCODE_KBDILLUMUP,
		key_KP_0 = SDL_SCANCODE_KP_0,
		key_KP_00 = SDL_SCANCODE_KP_00,
		key_KP_000 = SDL_SCANCODE_KP_000,
		key_KP_1 = SDL_SCANCODE_KP_1,
		key_KP_2 = SDL_SCANCODE_KP_2,
		key_KP_3 = SDL_SCANCODE_KP_3,
		key_KP_4 = SDL_SCANCODE_KP_4,
		key_KP_5 = SDL_SCANCODE_KP_5,
		key_KP_6 = SDL_SCANCODE_KP_6,
		key_KP_7 = SDL_SCANCODE_KP_7,
		key_KP_8 = SDL_SCANCODE_KP_8,
		key_KP_9 = SDL_SCANCODE_KP_9,
		key_KP_A = SDL_SCANCODE_KP_A,
		key_KP_AMPERSAND = SDL_SCANCODE_KP_AMPERSAND,
		key_KP_AT = SDL_SCANCODE_KP_AT,
		key_KP_B = SDL_SCANCODE_KP_B,
		key_KP_BACKSPACE = SDL_SCANCODE_KP_BACKSPACE,
		key_KP_BINARY = SDL_SCANCODE_KP_BINARY,
		key_KP_C = SDL_SCANCODE_KP_C,
		key_KP_CLEAR = SDL_SCANCODE_KP_CLEAR,
		key_KP_CLEARENTRY = SDL_SCANCODE_KP_CLEARENTRY,
		key_KP_COLON = SDL_SCANCODE_KP_COLON,
		key_KP_COMMA = SDL_SCANCODE_KP_COMMA,
		key_KP_D = SDL_SCANCODE_KP_D,
		key_KP_DBLAMPERSAND = SDL_SCANCODE_KP_DBLAMPERSAND,
		key_KP_DBLVERTICALBAR = SDL_SCANCODE_KP_DBLVERTICALBAR,
		key_KP_DECIMAL = SDL_SCANCODE_KP_DECIMAL,
		key_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
		key_KP_E = SDL_SCANCODE_KP_E,
		key_KP_ENTER = SDL_SCANCODE_KP_ENTER,
		key_KP_EQUALS = SDL_SCANCODE_KP_EQUALS,
		key_KP_EQUALSAS400 = SDL_SCANCODE_KP_EQUALSAS400,
		key_KP_EXCLAM = SDL_SCANCODE_KP_EXCLAM,
		key_KP_F = SDL_SCANCODE_KP_F,
		key_KP_GREATER = SDL_SCANCODE_KP_GREATER,
		key_KP_HASH = SDL_SCANCODE_KP_HASH,
		key_KP_HEXADECIMAL = SDL_SCANCODE_KP_HEXADECIMAL,
		key_KP_LEFTBRACE = SDL_SCANCODE_KP_LEFTBRACE,
		key_KP_LEFTPAREN = SDL_SCANCODE_KP_LEFTPAREN,
		key_KP_LESS = SDL_SCANCODE_KP_LESS,
		key_KP_MEMADD = SDL_SCANCODE_KP_MEMADD,
		key_KP_MEMCLEAR = SDL_SCANCODE_KP_MEMCLEAR,
		key_KP_MEMDIVIDE = SDL_SCANCODE_KP_MEMDIVIDE,
		key_KP_MEMMULTIPLY = SDL_SCANCODE_KP_MEMMULTIPLY,
		key_KP_MEMRECALL = SDL_SCANCODE_KP_MEMRECALL,
		key_KP_MEMSTORE = SDL_SCANCODE_KP_MEMSTORE,
		key_KP_MEMSUBTRACT = SDL_SCANCODE_KP_MEMSUBTRACT,
		key_KP_MINUS = SDL_SCANCODE_KP_MINUS,
		key_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
		key_KP_OCTAL = SDL_SCANCODE_KP_OCTAL,
		key_KP_PERCENT = SDL_SCANCODE_KP_PERCENT,
		key_KP_PERIOD = SDL_SCANCODE_KP_PERIOD,
		key_KP_PLUS = SDL_SCANCODE_KP_PLUS,
		key_KP_PLUSMINUS = SDL_SCANCODE_KP_PLUSMINUS,
		key_KP_POWER = SDL_SCANCODE_KP_POWER,
		key_KP_RIGHTBRACE = SDL_SCANCODE_KP_RIGHTBRACE,
		key_KP_RIGHTPAREN = SDL_SCANCODE_KP_RIGHTPAREN,
		key_KP_SPACE = SDL_SCANCODE_KP_SPACE,
		key_KP_TAB = SDL_SCANCODE_KP_TAB,
		key_KP_VERTICALBAR = SDL_SCANCODE_KP_VERTICALBAR,
		key_KP_XOR = SDL_SCANCODE_KP_XOR,
		key_l = SDL_SCANCODE_L,
		key_LALT = SDL_SCANCODE_LALT,
		key_LCTRL = SDL_SCANCODE_LCTRL,
		key_LEFT = SDL_SCANCODE_LEFT,
		key_LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
		key_LGUI = SDL_SCANCODE_LGUI,
		key_LSHIFT = SDL_SCANCODE_LSHIFT,
		key_m = SDL_SCANCODE_M,
		key_MAIL = SDL_SCANCODE_MAIL,
		key_MEDIASELECT = SDL_SCANCODE_MEDIASELECT,
		key_MENU = SDL_SCANCODE_MENU,
		key_MINUS = SDL_SCANCODE_MINUS,
		key_MODE = SDL_SCANCODE_MODE,
		key_MUTE = SDL_SCANCODE_MUTE,
		key_n = SDL_SCANCODE_N,
		key_NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR,
		key_o = SDL_SCANCODE_O,
		key_OPER = SDL_SCANCODE_OPER,
		key_OUT = SDL_SCANCODE_OUT,
		key_p = SDL_SCANCODE_P,
		key_PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
		key_PAGEUP = SDL_SCANCODE_PAGEUP,
		key_PASTE = SDL_SCANCODE_PASTE,
		key_PAUSE = SDL_SCANCODE_PAUSE,
		key_PERIOD = SDL_SCANCODE_PERIOD,
		key_POWER = SDL_SCANCODE_POWER,
		key_PRINTSCREEN = SDL_SCANCODE_PRINTSCREEN,
		key_PRIOR = SDL_SCANCODE_PRIOR,
		key_q = SDL_SCANCODE_Q,
		key_r = SDL_SCANCODE_R,
		key_RALT = SDL_SCANCODE_RALT,
		key_RCTRL = SDL_SCANCODE_RCTRL,
		key_RETURN = SDL_SCANCODE_RETURN,
		key_RETURN2 = SDL_SCANCODE_RETURN2,
		key_RGUI = SDL_SCANCODE_RGUI,
		key_RIGHT = SDL_SCANCODE_RIGHT,
		key_RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
		key_RSHIFT = SDL_SCANCODE_RSHIFT,
		key_s = SDL_SCANCODE_S,
		key_SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
		key_SELECT = SDL_SCANCODE_SELECT,
		key_SEMICOLON = SDL_SCANCODE_SEMICOLON,
		key_SEPARATOR = SDL_SCANCODE_SEPARATOR,
		key_SLASH = SDL_SCANCODE_SLASH,
		key_SLEEP = SDL_SCANCODE_SLEEP,
		key_SPACE = SDL_SCANCODE_SPACE,
		key_STOP = SDL_SCANCODE_STOP,
		key_SYSREQ = SDL_SCANCODE_SYSREQ,
		key_t = SDL_SCANCODE_T,
		key_TAB = SDL_SCANCODE_TAB,
		key_THOUSANDSSEPARATOR = SDL_SCANCODE_THOUSANDSSEPARATOR,
		key_u = SDL_SCANCODE_U,
		key_UNDO = SDL_SCANCODE_UNDO,
		key_UNKNOWN = SDL_SCANCODE_UNKNOWN,
		key_UP = SDL_SCANCODE_UP,
		key_v = SDL_SCANCODE_V,
		key_VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN,
		key_VOLUMEUP = SDL_SCANCODE_VOLUMEUP,
		key_w = SDL_SCANCODE_W,
		key_WWW = SDL_SCANCODE_WWW,
		key_x = SDL_SCANCODE_X,
		key_y = SDL_SCANCODE_Y,
		key_z = SDL_SCANCODE_Z,
	};

	enum class mouse_button {
		left = SDL_BUTTON_LEFT,
		mid = SDL_BUTTON_MIDDLE,
		right = SDL_BUTTON_RIGHT
	};

	// Manages input from the keyboard and mouse
	class input_manager final {
	public:

		input_manager();

		// Processes input events from the SDL event queue
		void process_input();

		// Disables input processing
		void disable();

		// Enables input processing
		void enable();

		// Checks if input processing is enabled
		bool is_processing_input();

		// Checks if a quit event was encountered
		bool is_quit_requested();

		// Checks if btn is currently being pressed
		bool is_mouse_pressed(mouse_button btn);

		// Checks if btn was pressed this frame
		bool is_mouse_down(mouse_button btn);

		// Checks if btn was released this frame
		bool is_mouse_up(mouse_button btn);

		// Returns the amount of vertical mouse wheel motion
		std::int32_t get_vertical_mouse_wheel_motion();

		// Returns the amount of horizontal mouse wheel motion
		std::int32_t get_horizontal_mouse_wheel_motion();

		// Returns the current position of the mouse NOTE: The position is found in each fn call.
		SDL_Point get_mouse_position(int cameraX = 0, int cameraY = 0);

		// Checks if key is currently being pressed
		bool is_key_pressed(keyboard key);

		// Checks if key was pressed this frame
		bool is_key_down(keyboard key);

		// Checks if key was released this frame
		bool is_key_up(keyboard key);

	private:
		// Maximum number of mouse buttons supported
		static const int MOUSE_BUTTON_MAX = 3;

		// Pointer to internal SDL keyboard state array
		const std::uint8_t* sdl_keyboard_state;

		// Number of keys as reported by SDL
		int num_keys;

		// Holds the statuses of keys released
		std::vector<bool> key_up;

		// Holds the statuses of keys pressed
		std::vector<bool> key_down;

		// Holds the statuses of mouse buttons pressed
		std::vector<bool> mouse_down;

		// Holds the statuses of the mouse buttons released
		std::vector<bool> mouse_up;

		// Holds the amount of vertical mouse wheel movement
		std::uint32_t mouse_wheel_y;

		// Holds the amount of horizontal mouse wheel movement
		std::uint32_t mouse_wheel_x;

		// Enables/disables input processing
		bool enabled = true;

		// If a quit event has been detected
		bool quit = false;
	};
}