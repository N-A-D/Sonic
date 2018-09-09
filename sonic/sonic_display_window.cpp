#include "sonic_display_window.h"

sonic::display::window::window(const std::string& title, int w, int h, std::uint32_t window_flags, std::uint32_t renderer_flags, int x, int y)
	: w(w), h(h), fullscreen(false), borderless(false), m_window(std::unique_ptr<SDL_Window, window_deleter>(SDL_CreateWindow(title.c_str(), x, y, w, h, window_flags)))
{
	if (!m_window)
		throw std::runtime_error(std::string("Could not create window -- ") + SDL_GetError());

	// Create the window's renderer
	w_id = SDL_GetWindowID(m_window.get());

	SDL_Renderer *renderer_ptr = SDL_CreateRenderer(m_window.get(), -1, renderer_flags);

	if (!renderer_ptr)
		throw std::runtime_error(std::string("Could not create renderer -- ") + SDL_GetError());

	context = sonic::display::renderer(renderer_ptr, w_id);
}

sonic::display::renderer sonic::display::window::renderer()
{
	return context;
}

void sonic::display::window::resize(int width, int height)
{
	SDL_SetWindowSize(m_window.get(), width, height);
	refresh();
}

void sonic::display::window::toggle_fullscreen()
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

void sonic::display::window::toggle_borders()
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

void sonic::display::window::move_to(int x, int y)
{
	SDL_SetWindowPosition(m_window.get(), x, y);
	refresh();
}

void sonic::display::window::restore()
{
	SDL_RestoreWindow(m_window.get());
	refresh();
	SDL_GetWindowSize(m_window.get(), &w, &h);
}

void sonic::display::window::maximize()
{
	SDL_MaximizeWindow(m_window.get());
	refresh();
	SDL_GetWindowSize(m_window.get(), &w, &h);
}

void sonic::display::window::minimize()
{
	SDL_MinimizeWindow(m_window.get());
}

void sonic::display::window::set_title(std::string title)
{
	SDL_SetWindowTitle(m_window.get(), title.c_str());
}

std::string sonic::display::window::title() const
{
	return std::string(SDL_GetWindowTitle(m_window.get()));
}

void sonic::display::window::set_brightness(int brightness)
{
	SDL_SetWindowBrightness(m_window.get(), static_cast<float>(brightness));
}

int sonic::display::window::brightness() const
{
	return static_cast<int>(SDL_GetWindowBrightness(m_window.get()));
}

std::uint32_t sonic::display::window::window_id() const
{
	return w_id;
}

int sonic::display::window::width() const
{
	return w;
}

int sonic::display::window::height() const
{
	return h;
}

void sonic::display::window::refresh() noexcept
{
	context.display();
}
