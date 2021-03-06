#include "player.h"
#include <stdexcept>
#include <SDL2/SDL.h>

struct AudioData {
	uint8_t* pos;
	uint32_t len;
};

static void callback(void* userdata, uint8_t* stream, int streamLength) {
	AudioData* audio = static_cast<AudioData*>(userdata);
    if (audio->len == 0) {
        return;
    }
	uint32_t len = (uint32_t)streamLength;
	len = (len > audio->len ? audio->len : len);
	SDL_memcpy(stream, audio->pos, len);
	audio->pos += len;
	audio->len -= len;
}

void playWAV(const char *filename) {
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec spec;
	uint8_t* start;
	uint32_t len;
    if (SDL_LoadWAV(filename, &spec, &start, &len) == NULL) {
        throw std::runtime_error("Unable to open the file");
    }
	AudioData audio = {start, len};
	spec.callback = callback;
	spec.userdata = &audio;
	SDL_AudioDeviceID device = 
        SDL_OpenAudioDevice(0, 0, &spec, 0, 
                SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (device == 0) {
        throw std::runtime_error("Unable to open sound device");
    }
	SDL_PauseAudioDevice(device, 0);
	while(audio.len > 0) {
		SDL_Delay(100);
	}
	SDL_CloseAudioDevice(device);
	SDL_FreeWAV(start);
	SDL_Quit();
}
