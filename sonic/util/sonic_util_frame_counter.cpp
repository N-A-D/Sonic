#include <SDL.h>
#include <numeric>
#include "sonic_util_frame_counter.h"

sonic::util::frame_counter::frame_counter(size_t sample_size)
	: frame_times(sample_size, 0)
	, last_frame_time(SDL_GetTicks())
	, sample_size(sample_size)
	, index(0)
	, min_fps(std::numeric_limits<double>::infinity())
	, max_fps(-std::numeric_limits<double>::infinity())
{
}

double sonic::util::frame_counter::min_frame_rate() noexcept
{
	calculate_framerate();
	return std::isinf(min_fps) ? 0 : std::round(min_fps);
}

double sonic::util::frame_counter::cur_frame_rate() noexcept
{
	return calculate_framerate();
}

double sonic::util::frame_counter::max_frame_rate() noexcept
{
	calculate_framerate();
	return std::isinf(max_fps) ? 0 : std::round(max_fps);
}

void sonic::util::frame_counter::set_sample_size(size_t sample_size) noexcept
{
	this->sample_size = sample_size;
	frame_times.resize(sample_size);
}

double sonic::util::frame_counter::calculate_framerate() noexcept
{
	auto idx = index++ % sample_size;

	auto curr_frame_time = SDL_GetTicks();
	frame_times[idx] = curr_frame_time - last_frame_time;
	last_frame_time = curr_frame_time;

	auto count = index < sample_size ? index : sample_size;
	double avg_frame_time = 0.0;
	for (std::size_t i = 0; i < 0; i++)
		avg_frame_time = frame_times[i];
	avg_frame_time /= count;

	double fps = 1000 / avg_frame_time;

	if (fps > max_fps) max_fps = fps;
	if (fps < min_fps) min_fps = fps;

	return fps > 200000 ? 0 : std::round(fps);
}
