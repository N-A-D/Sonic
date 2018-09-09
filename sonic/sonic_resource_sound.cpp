#include <string>
#include <stdexcept>
#include "sonic_resource_sound.h"

sonic::resource::audio_effect::audio_effect() : chunk(nullptr)
{
}

sonic::resource::audio_effect::audio_effect(const std::string& path) : chunk(std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(path.c_str()), [](Mix_Chunk* c) { Mix_FreeChunk(c); }))
{
	if (!chunk)
		throw std::runtime_error("Could not load audio sample from path: " + path + " -- " + Mix_GetError());
}

sonic::resource::audio_effect::audio_effect(const std::string& path, int volume) : chunk(std::shared_ptr<Mix_Chunk>(Mix_LoadWAV(path.c_str()), [](Mix_Chunk* c) { Mix_FreeChunk(c); }))
{
	if (!chunk)
		throw std::runtime_error("Could not load audio sample from path: " + path + " -- " + Mix_GetError());
	this->set_volume(volume);
}

sonic::resource::audio_effect::operator bool() const noexcept
{
	return chunk.get() != nullptr;
}

void sonic::resource::audio_effect::set_volume(int value)
{
	assert(chunk && "Cannot set the volume of an invalid audio sample.");
	Mix_VolumeChunk(chunk.get(), value);
}

void sonic::resource::audio_effect::play(int channel, int loops)
{
	assert(chunk && "Cannot play an invalid audio sample.");
	Mix_PlayChannel(channel, chunk.get(), loops);
}

void sonic::resource::audio_effect::play_timed(int channel, int loops, int duration)
{
	assert(chunk && "Cannot play an invalid audio sample.");
	Mix_PlayChannelTimed(channel, chunk.get(), loops, duration);
}

void sonic::resource::audio_effect::fade_in(int channel, int loops, int fade_in_time)
{
	assert(chunk && "Cannot play an invalid audio sample.");
	Mix_FadeInChannel(channel, chunk.get(), loops, fade_in_time);
}

void sonic::resource::audio_effect::fade_in_timed(int channel, int loops, int fade_in_time, int duration)
{
	assert(chunk && "Cannot play an invalid audio sample.");
	Mix_FadeInChannelTimed(channel, chunk.get(), loops, fade_in_time, duration);
}

// music Implementation below

sonic::resource::music::music() : track(nullptr)
{
}

sonic::resource::music::music(const std::string& path) : track(std::shared_ptr<Mix_Music>(Mix_LoadMUS(path.c_str()), [](Mix_Music* m) { Mix_FreeMusic(m); }))
{
	if (!track)
		throw std::runtime_error("Could not load track track from path: " + path + " -- " + Mix_GetError());
}

sonic::resource::music::operator bool() const noexcept
{
	return track.get() != nullptr;
}

void sonic::resource::music::play(int loops)
{
	assert(track && "Cannot play an invalid track track.");
	Mix_PlayMusic(track.get(), loops);
}

void sonic::resource::music::fade_in(int loops, int fade_in_time)
{
	assert(track && "Cannot play an invalid track track.");
	Mix_FadeInMusic(track.get(), loops, fade_in_time);
}


// Sound management functions below
void sonic::resource::snd_mgmt::allocate_channels(int n)
{
	Mix_AllocateChannels(n);
}

void sonic::resource::snd_mgmt::set_channel_volume(int channel, int volume)
{
	Mix_Volume(channel, volume);
}

void sonic::resource::snd_mgmt::pause_channel_playback(int channel)
{
	Mix_Pause(channel);
}

void sonic::resource::snd_mgmt::resume_channel_playback(int channel)
{
	Mix_Resume(channel);
}

void sonic::resource::snd_mgmt::halt_channel_playback(int channel)
{
	Mix_HaltChannel(channel);
}

void sonic::resource::snd_mgmt::exipre_channel_playback(int channel, int duration)
{
	Mix_ExpireChannel(channel, duration);
}

void sonic::resource::snd_mgmt::fade_out_channel(int channel, int duration)
{
	Mix_FadeOutChannel(channel, duration);
}

int sonic::resource::snd_mgmt::is_channel_playing(int channel)
{
	return Mix_Playing(channel);
}

int sonic::resource::snd_mgmt::is_channel_paused(int channel)
{
	return Mix_Paused(channel);
}

void sonic::resource::snd_mgmt::set_music_volume(int value)
{
	Mix_VolumeMusic(value);
}

void sonic::resource::snd_mgmt::pause_music_playback()
{
	Mix_PauseMusic();
}

void sonic::resource::snd_mgmt::resume_music_playback()
{
	Mix_ResumeMusic();
}

void sonic::resource::snd_mgmt::rewind_music()
{
	Mix_RewindMusic();
}

void sonic::resource::snd_mgmt::halt_music_playback()
{
	Mix_HaltMusic();
}

void sonic::resource::snd_mgmt::fade_out_music(int duration)
{
	Mix_FadeOutMusic(duration);
}

bool sonic::resource::snd_mgmt::is_music_playing()
{
	return (Mix_PlayingMusic() != 0) ? true : false;
}

bool sonic::resource::snd_mgmt::is_music_paused()
{
	return (Mix_PausedMusic() != 0) ? true : false;
}
