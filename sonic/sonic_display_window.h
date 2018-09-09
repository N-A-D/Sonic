#pragma once

#include <SDL.h>
#include <string>
#include <memory>
#include <stdint.h>
#include "sonic_display_renderer.h"

namespace sonic {
	namespace display {

		// The window class
		class window final {
		public:
			// Creates a new Window
			window(const std::string& title = "",			         // Window title
				int w = 640, int h = 480,                                // Window dimensions
				std::uint32_t window_flags = SDL_WINDOW_SHOWN,           // Window creation flags
				std::uint32_t renderer_flags = SDL_RENDERER_ACCELERATED, // Renderer creation flags
				int x = SDL_WINDOWPOS_UNDEFINED,                         // Window x position
				int y = SDL_WINDOWPOS_UNDEFINED				 // Windiow y position
			);

			// Returns the rendering context for this window
			sonic::display::renderer renderer();

			// Sets the dimensions of the Window
			void resize(int width, int height);

			// Sets the Window to fullscreen mode
			void toggle_fullscreen();

			// Removes window borders around the window screen
			void toggle_borders();

			// Sets the position of the window
			void move_to(int x, int y);

			// Restores the size and position of a minimized or maximized window
			void restore();

			// Maximizes the window
			void maximize();

			// Minimizes the window
			void minimize();

			// Sets the title of the window
			void set_title(std::string title);

			// Gets the title of the window
			std::string title() const;

			// Sets the brightness of the Window
			void set_brightness(int brightness);

			// Gets the brightness of the Window
			int brightness() const;

			// Returns the Window's id
			std::uint32_t window_id() const;

			// Returns the width of the screen
			int width() const;

			// Returns the height of the screen
			int height() const;

		private:
			void refresh() noexcept;

			struct window_deleter {
				void operator()(SDL_Window* w) { SDL_DestroyWindow(w); }
			};

			// The internally managed SDL_Window
			std::unique_ptr<SDL_Window, window_deleter> m_window;

			// The rendering context
			sonic::display::renderer context;

			// The window id
			std::uint32_t w_id;

			// dimensions
			int w, h;

			// toggles
			bool fullscreen, borderless;
		};
		
	}
}
