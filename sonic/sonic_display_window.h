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
			window(int width                                              // Window width
				  , int height                                            // Window height
				  , const std::string& title="Generic window"             // Window title
				  , std::uint32_t window_flags=SDL_WINDOW_SHOWN           // Window flags
				  , std::uint32_t renderer_flags=SDL_RENDERER_ACCELERATED // Renderer flags
				  , int x=SDL_WINDOWPOS_UNDEFINED                         // Starting x position
				  , int y=SDL_WINDOWPOS_UNDEFINED                         // Starting y position
			      );

			// Returns the rendering context for this window
			sonic::display::renderer renderer() const noexcept;

			// Sets the dimensions of the Window
			// Note: Nothing happens if this window was created without the SDL_WINDOW_RESIZABLE flag
			void resize(int width, int height) noexcept;

			// Sets the Window to fullscreen mode
			void toggle_fullscreen() noexcept;

			// Removes window borders around the window screen
			void toggle_borders() noexcept;

			// Centers the screen if it isn't already centered
			void center() noexcept;

			// Checks if this window is minimized
			bool is_minimized() const noexcept;

			// Checks if this window is maximized
			bool is_maximized() const noexcept;

			// Checks if this window is resizable
			bool is_resizable() const noexcept;

			// Checks if this window is fullscreen
			bool is_fullscreen() const noexcept;

			// Checks if this window is borderless
			bool is_borderless() const noexcept;
			
			// Checks if this window has mouse focus
			bool has_mouse_focus() const noexcept;
		
			// Checks if this window has keyboard focus
			bool has_keyboard_focus() const noexcept;

			// Sets the title of the window
			void set_title(std::string title) noexcept;

			// Gets the title of the window
			std::string title() const noexcept;

			// Sets the brightness of the Window
			void set_brightness(int brightness) noexcept;

			// Gets the brightness of the Window
			int brightness() const noexcept;

			// Sets the window icon 
			void set_window_icon(SDL_Surface* icon) noexcept;

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
