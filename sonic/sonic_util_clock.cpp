#include "sonic_util_clock.h"

sonic::util::clock::clock() : start_time(SDL_GetTicks()), pause_time(0), _is_paused(false), _is_started(false)
{
}

void sonic::util::clock::start()
{
	_is_started = true;
	_is_paused = false;

	start_time = SDL_GetTicks();
	pause_time = 0;
}

void sonic::util::clock::stop()
{
	_is_started = false;
	_is_paused = false;

	start_time = 0;
	pause_time = 0;
}

void sonic::util::clock::pause()
{
	if (_is_started && !_is_paused) {
		_is_paused = true;
		pause_time = SDL_GetTicks() - start_time;
		start_time = 0;
	}
}

void sonic::util::clock::unpause()
{
	if (_is_started && _is_paused) {
		_is_paused = false;
		start_time = SDL_GetTicks() - pause_time;
		pause_time = 0;
	}
}

std::uint32_t sonic::util::clock::get_ticks() const noexcept
{
	if (_is_started) {
		if (_is_paused) {
			return pause_time;
		}
		else {
			return SDL_GetTicks() - start_time;
		}
	}
	else {
		return 0;
	}
}

bool sonic::util::clock::is_started() const noexcept
{
	return _is_started;
}

bool sonic::util::clock::is_paused() const noexcept
{
	return _is_paused;
}

