#pragma once

#include <SDL.h>
#include <cstdint>

namespace sonic {
	namespace util {

		// A generic clock
		class clock final {
		public:
			// Creates a new timer. 
			clock();

			// clock functions

			// Starts/Restarts the clock
			void start() noexcept;

			// Stop the clock. Effectively resetting it
			void stop() noexcept;

			// Pauses the clock
			void pause() noexcept;

			// Unpauses the clock
			void unpause() noexcept;

			// Returns the time (in milliseconds) delta from the previous call
			std::uint32_t get_ticks() const noexcept;

			// Checks if the clock is started
			bool is_started() const noexcept;

			// Checks if the clock is paused
			bool is_paused() const noexcept;

		private:

			// Time since the clock started
			std::uint32_t start_time;

			// Time the clock spent paused
			std::uint32_t pause_time;

			// Timer status
			bool _is_started, _is_paused;
		};
	}
}