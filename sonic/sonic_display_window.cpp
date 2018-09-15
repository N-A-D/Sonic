#include "sonic_display_window.h"

sonic::display::window::window(int w, int h, const std::string& title, std::uint32_t window_flags, std::uint32_t renderer_flags, int x, int y)
	: w(w), h(h), fullscreen(false), borderless(false), m_window(std::unique_ptr<SDL_Window, window_deleter>(SDL_CreateWindow(title.c_str(), x, y, w, h, window_flags)))
{
	if (!m_window)
		throw std::runtime_error(std::string("Could not create window -- ") + SDL_GetError());

	// Initialize the window's id
	w_id = SDL_GetWindowID(m_window.get());

	// Create the window's renderer
	create_display_renderer(renderer_flags);
}

sonic::display::renderer sonic::display::window::renderer() const noexcept
{
	return context;
}

void sonic::display::window::resize(int width, int height) noexcept
{
	if ((SDL_WINDOW_RESIZABLE & SDL_GetWindowFlags(m_window.get())) != SDL_WINDOW_RESIZABLE) return;
	SDL_SetWindowSize(m_window.get(), width, height);
	refresh();
}

void sonic::display::window::toggle_fullscreen() noexcept
{
	if (fullscreen) {
		fullscreen = false;
		SDL_SetWindowFullscreen(m_window.get(), 0);
		refresh();
		SDL_GetWindowSize(m_window.get(), &w, &h);
	}
	else {
		fullscreen = true;
		SDL_SetWindowFullscreen(m_window.get(), SDL_WINDOW_FULLSCREEN);
		refresh();
		SDL_GetWindowSize(m_window.get(), &w, &h);
	}
}

void sonic::display::window::toggle_borders() noexcept
{
	if (borderless) {
		borderless = false;
		SDL_SetWindowBordered(m_window.get(), SDL_FALSE);
	}
	else {
		borderless = true;
		SDL_SetWindowBordered(m_window.get(), SDL_TRUE);
	}
}

void sonic::display::window::center() noexcept
{
	SDL_SetWindowPosition(m_window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

bool sonic::display::window::is_minimized() const noexcept
{
	return (SDL_GetWindowFlags(m_window.get()) & SDL_WINDOW_MINIMIZED) == SDL_WINDOW_MINIMIZED;
}

bool sonic::display::window::is_maximized() const noexcept
{
	return (SDL_GetWindowFlags(m_window.get()) & SDL_WINDOW_MAXIMIZED) == SDL_WINDOW_MAXIMIZED;
}

bool sonic::display::window::is_resizable() const noexcept
{
	return (SDL_GetWindowFlags(m_window.get()) & SDL_WINDOW_RESIZABLE) == SDL_WINDOW_RESIZABLE;
}

bool sonic::display::window::is_fullscreen() const noexcept
{
	return fullscreen;
}

bool sonic::display::window::is_borderless() const noexcept
{
	return borderless;
}

bool sonic::display::window::has_mouse_focus() const noexcept
{
	return (SDL_GetWindowFlags(m_window.get()) & SDL_WINDOW_INPUT_FOCUS) == SDL_WINDOW_INPUT_FOCUS;
}

bool sonic::display::window::has_keyboard_focus() const noexcept
{
	return (SDL_GetWindowFlags(m_window.get()) & SDL_WINDOW_MOUSE_FOCUS) == SDL_WINDOW_MOUSE_FOCUS;
}


void sonic::display::window::set_title(std::string title) noexcept
{
	SDL_SetWindowTitle(m_window.get(), title.c_str());
}

std::string sonic::display::window::title() const noexcept
{
	return std::string(SDL_GetWindowTitle(m_window.get()));
}

void sonic::display::window::set_brightness(int brightness)  noexcept
{
	SDL_SetWindowBrightness(m_window.get(), static_cast<float>(brightness));
}

int sonic::display::window::brightness() const noexcept
{
	return static_cast<int>(SDL_GetWindowBrightness(m_window.get()));
}

void sonic::display::window::set_window_icon(SDL_Surface * icon) noexcept
{
	SDL_SetWindowIcon(m_window.get(), icon);
}

std::uint32_t sonic::display::window::window_id() const noexcept
{
	return w_id;
}

int sonic::display::window::width() const noexcept
{
	return w;
}

int sonic::display::window::height() const noexcept
{
	return h;
}

void sonic::display::window::create_display_renderer(std::uint32_t renderer_flags)
{
	SDL_Renderer *renderer_ptr = SDL_CreateRenderer(m_window.get(), -1, renderer_flags);

	if (!renderer_ptr)
		throw std::runtime_error(std::string("Could not create renderer -- ") + SDL_GetError());

	context = sonic::display::renderer(renderer_ptr, w_id);
}

void sonic::display::window::refresh() noexcept
{
	context.display();
}
