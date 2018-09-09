#include <SDL.h>
#include "sonic_util_fps_counter.h"


sonic::util::fps_counter::fps_counter(size_t num_samples)
	: frame_samples(num_samples, 0), frame_count(0), num_samples(num_samples)
{
	last_frame_time = SDL_GetTicks();
}

double sonic::util::fps_counter::avg_fps() noexcept
{
	auto idx = this->frame_count++ % this->num_samples;

	auto curr_ticks = SDL_GetTicks();

	this->frame_samples[idx] = curr_ticks - this->last_frame_time;

	this->last_frame_time = curr_ticks;

	auto count = this->frame_count < this->num_samples ? this->frame_count : this->num_samples;

	double fps = 0.0;

	for (std::uint32_t i = 0; i < count; i++)
		fps += this->frame_samples[i];

	fps /= count;

	return (1000.0 / fps) > 2000000 ? 0 : (1000.0 / fps);
}

void sonic::util::fps_counter::set_num_samples(size_t num_samples) noexcept
{
	this->num_samples = num_samples;
	this->frame_samples.resize(num_samples);
}