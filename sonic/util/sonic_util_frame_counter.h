#pragma once

#include <vector>
#include <cstdint>

namespace sonic {
	namespace util {

		class frame_counter {
		public:

			frame_counter(size_t sample_size = 10000);

			// Returns the minimum frame rate
			double min_frame_rate() noexcept;

			// Returns the average frame rate
			double cur_frame_rate() noexcept;

			// Returns the maximum frame rate
			double max_frame_rate() noexcept;

			// Sets the frame count sample size
			void set_sample_size(size_t num_samples) noexcept;

		private:

			// Calculates the minimum and maximum frames per second
			double calculate_framerate() noexcept;

			// The container to store frame times
			std::vector<std::uint32_t> frame_times;
			// The frame time calculated last frame
			std::uint32_t last_frame_time;
			// The current sample size
			std::size_t sample_size;
			// The index into the frame time container
			std::size_t index;
			
			// current min and max fps
			double min_fps, max_fps;
		};

	}
}