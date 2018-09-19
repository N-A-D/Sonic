#include "sonic_util_frame_timer.h"

sonic::util::frame_timer::frame_timer()
{
}

double sonic::util::frame_timer::delta_time() noexcept
{
	auto dt = timer.get_ticks() / 1000.0;
	timer.start();
	return dt;
}
