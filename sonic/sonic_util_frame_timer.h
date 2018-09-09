#pragma once

#include "sonic_util_clock.h"

namespace sonic {
	namespace util {

		class frame_timer {
		public:
			frame_timer();
			double delta_time() noexcept;
		private:
			sonic::util::clock timer;
		};

	}
}