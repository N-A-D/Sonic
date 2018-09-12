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
			sonic::display::renderer renderer() const noexcept;

			// Sets the dimensions of the Window
			void resize(int width, int height) noexcept;

			// Sets the Window to fullscreen mode
			void toggle_fullscreen() noexcept;

			// Removes window borders around the window screen
			void toggle_borders() noexcept;

			// Sets the position of the window
			void move_to(int x, int y) noexcept;

			// Restores the size and position of a minimized or maximized window
			void restore() noexcept;

			// Maximizes the window
			void maximize() noexcept;

			// Minimizes the window
			void minimize() noexcept;

			// Sets the title of the window
			void set_title(std::string title) noexcept;

			// Gets the title of the window
			std::string title() const noexcept;

			// Sets the brightness of the Window
			void set_brightness(int brightness) noexcept;

			// Gets the brightness of the Window
			int brightness() const noexcept;

			// Returns the Window's id
			std::uint32_t window_id() const noexcept;

			// Returns the width of the screen
			int width() const noexcept;

			// Returns the height of the screen
			int height() const noexcept;

		private:
			// Creates the display::renderer for this display::window
			void create_display_renderer(std::uint32_t renderer_flags);
			
			// Refreshes the screen after significant changes
			void refresh() noexcept;

			// Custom deleter for SDL_Window* 
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
