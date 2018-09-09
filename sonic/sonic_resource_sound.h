#pragma once

#include <string>
#include <memory>
#include <SDL_mixer.h>
#include "sonic_resource.h"

namespace sonic {
	namespace resource {

		// The audio_effect class
		// Used for sound effects
		class audio_effect final : public sonic::resource::resource_type<audio_effect> {
		public:
			// Constructors
			audio_effect();
			audio_effect(const std::string& path);
			audio_effect(const std::string& path, int volume);

			operator bool() const noexcept;

			// Sets the volume for the sound sample
			void set_volume(int value);

			// Plays this sample
			// channel: The channel to play on. -1 for the first unreserved channel
			// loops: The number of times to loop. -1 is infinite.
			void play(int channel, int loops);

			// Timed playback of this sample
			// channel: The channel to play on. -1 for the first unreserved channel
			// loops: The number of times to loop. -1 is infinite.
			// duration: How long (milliseconds) to play the sample
			void play_timed(int channel, int loops, int duration);

			// Fade-in this sample
			// channel: The channel to play on. -1 for the first unreserved channel
			// loops: The number of times to loop. -1 is infinite.
			// fade_in_time: Time that the fade-in effect should take from silence to full volume 
			void fade_in(int channel, int loops, int fade_in_time);

			// Timed Fade-in of this sample
			// channel: The channel to play on. -1 for the first unreserved channel
			// loops: The number of times to loop. -1 is infinite.
			// fade_in_time: Time that the fade-in effect should take from silence to full volume 
			// duration: The time to play the sample.
			void fade_in_timed(int channel, int loops, int fade_in_time, int duration);

		private:
			std::shared_ptr<Mix_Chunk> chunk;
		};

		// The music class
		class music final : public sonic::resource::resource_type<music> {
		public:
			music();
			music(const std::string& path);

			operator bool() const noexcept;

			// Plays this music track
			// loops: The number of times to loop. -1 is infinite
			void play(int loops);

			// Fade-in this music track
			// loops: The number of times to loop. -1 is infinite
			// fade_in_time: The time to fade in
			void fade_in(int loops, int fade_in_time);

		private:
			std::shared_ptr<Mix_Music> track;
		};


		// Utility namespace specifically for managing the two sound types
		namespace snd_mgmt {

			// Allocates a given number of channels
			// n: The number of channels to allocate
			void allocate_channels(int n);

			// Sets the volume for a given channel
			// channel: The channel to set the volume for. -1 will set the volume for all allocated channels.
			void set_channel_volume(int channel, int volume);

			// Pauses sample playback for a given channel
			// channel: The channel to pause playback. -1 will pause playback on all allocated channels.
			void pause_channel_playback(int channel);

			// Resumes sample playback for a given channel
			// channel: The channel to resume playback. -1 will resume playback for all allocated channels
			void resume_channel_playback(int channel);

			// Halts sample playback for a given channel
			// channel: The channel to halt playback. -1 will halt playback for all allocated channels
			void halt_channel_playback(int channel);

			// Halts sample playback after a given time in milliseconds
			// channel: The channel to expire. -1 will halt playback for all allocated channels after the given duration
			void exipre_channel_playback(int channel, int duration);

			// Fades out playback for a given channel
			// channel: The channel to fade out. -1 will fade out playback for all allocated channels
			// duration: The fade out time.
			void fade_out_channel(int channel, int duration);

			// Returns the number of channels playing
			// channel: The channel to check. -1 will check if any of the allocated channels are playing
			int is_channel_playing(int channel);

			// Returns the number of channels paused
			// channel: The channel to check. -1 will check if any of the allocated channels are paused
			int is_channel_paused(int channel);

			// Sets the music volume
			// value: The music volume
			void set_music_volume(int value);

			// Pauses music playback
			void pause_music_playback();

			// Resumes music playback
			void resume_music_playback();

			// Rewinds the music to the start
			void rewind_music();

			// Stops music playback
			void halt_music_playback();

			// Fades out music
			// duration: The fade out time.
			void fade_out_music(int duration);

			// Checks if music is actively playing or not
			bool is_music_playing();

			// Checks if music is paused or not
			bool is_music_paused();
		}

	}
}