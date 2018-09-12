#include "sonic_input.h"

sonic::input_manager::input_manager()
{
	sdl_keyboard_state = SDL_GetKeyboardState(&num_keys);
	key_down = std::vector<bool>(num_keys, false);
	key_up = std::vector<bool>(num_keys, false);
	mouse_down = std::vector<bool>(MOUSE_BUTTON_MAX, false);
	mouse_up = std::vector<bool>(MOUSE_BUTTON_MAX, false);
}

void sonic::input_manager::process_input() noexcept
{
	using sz = std::vector<bool>::size_type;

	for (sz i = 0; i != MOUSE_BUTTON_MAX; ++i)
		mouse_down[i] = mouse_up[i] = false;
	for (sz i = 0; i != num_keys; ++i)
		key_down[i] = key_up[i] = false;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {

		case SDL_QUIT:
			quit = true;
			break;

		case SDL_KEYDOWN:
			sdl_keyboard_state = SDL_GetKeyboardState(&num_keys);
			key_down[static_cast<sz>(event.key.keysym.scancode)] = true;
			break;

		case SDL_KEYUP:
			sdl_keyboard_state = SDL_GetKeyboardState(&num_keys);
			key_up[static_cast<sz>(event.key.keysym.scancode)] = true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
				mouse_down[0] = true;
			else if (event.button.button == SDL_BUTTON_MIDDLE)
				mouse_down[1] = true;
			else if (event.button.button == SDL_BUTTON_RIGHT)
				mouse_down[2] = true;
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
				mouse_up[0] = true;
			else if (event.button.button == SDL_BUTTON_MIDDLE)
				mouse_up[1] = true;
			else if (event.button.button == SDL_BUTTON_RIGHT)
				mouse_up[2] = true;
			break;

		case SDL_MOUSEWHEEL:
			mouse_wheel_y = event.wheel.y;
			mouse_wheel_x = event.wheel.x;
			break;

		}
	}
}

void sonic::input_manager::disable() noexcept
{
	enabled = false;
}

void sonic::input_manager::enable() noexcept
{
	enabled = true;
}

bool sonic::input_manager::is_processing_input() const noexcept
{
	return enabled;
}

bool sonic::input_manager::is_quit_requested() const noexcept
{
	return quit;
}

bool sonic::input_manager::is_mouse_pressed(mouse_button btn) const noexcept
{
	if (!enabled) {
		return false;
	}
	else {
		switch (btn) {
		case mouse_button::left:
			return SDL_GetMouseState(nullptr, nullptr) & static_cast<int>(mouse_button::left);
		case mouse_button::mid:
			return SDL_GetMouseState(nullptr, nullptr) & static_cast<int>(mouse_button::mid);
		case mouse_button::right:
			return SDL_GetMouseState(nullptr, nullptr) & static_cast<int>(mouse_button::right);
		default:
			return false;
		}
	}
}

bool sonic::input_manager::is_mouse_down(mouse_button btn) const noexcept
{
	return (this->enabled) ? mouse_down[static_cast<std::vector<bool>::size_type>(btn) - 1] : false;
}

bool sonic::input_manager::is_mouse_up(mouse_button btn) const noexcept
{
	return (this->enabled) ? mouse_up[static_cast<std::vector<bool>::size_type>(btn) - 1] : false;
}

std::int32_t sonic::input_manager::vertical_mouse_wheel_motion() const noexcept
{
	return mouse_wheel_y;
}

std::int32_t sonic::input_manager::horizontal_mouse_wheel_motion() const noexcept
{
	return mouse_wheel_x;
}

SDL_Point sonic::input_manager::mouse_position(int cameraX, int cameraY) const noexcept
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return { x + cameraX, y + cameraY };
}

bool sonic::input_manager::is_key_pressed(keyboard key) const noexcept
{
	return (this->enabled) ? sdl_keyboard_state[static_cast<SDL_Scancode>(key)] : false;
}

bool sonic::input_manager::is_key_down(keyboard key) const noexcept
{
	return (this->enabled) ? key_down[static_cast<std::vector<bool>::size_type>(key)] : false;
}

bool sonic::input_manager::is_key_up(keyboard key) const noexcept
{
	return (this->enabled) ? key_up[static_cast<std::vector<bool>::size_type>(key)] : false;
}
