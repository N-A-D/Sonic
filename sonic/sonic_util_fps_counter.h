#pragma once

#include <vector>
#include <cstdint>

namespace sonic {
	namespace util {

		class fps_counter {
		public:
			fps_counter(size_t num_samples = 10000);

			double avg_fps() noexcept;

			void set_num_samples(size_t num_samples) noexcept;

		private:
			// The container to store frame times
			std::vector<std::uint32_t> frame_samples;

			std::uint32_t last_frame_time;
			std::uint32_t frame_count;

			size_t num_samples;
		};

	}
}