#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <SDL_Mixer/SDL_mixer.h>
#include <string>
#include <map>

namespace Bengine{

    class SoundEffect{
        public:
            friend class AudioEngine;

            void play(int loops = 0);

        private:
            Mix_Chunk* m_chunk = nullptr;
    };

    class Music{
        public:
            friend class AudioEngine;

            ///plays the audio file
            ///@param loops: if loops = -1, loops forever,
            ///otherwise play it loops times
            void play(int loops = -1);

            static void pause();
            static void stop();
            static void resume();

        private:
            Mix_Music* m_music = nullptr;

    };

    class AudioEngine
    {
        public:
            AudioEngine();
            virtual ~AudioEngine();

            void init();
            void destroy();

            SoundEffect loadSoundEffect(const std::string& filePath);
            Music loadMusic(const std::string& filePath);

        protected:

        private:
            std::map<std::string, Mix_Chunk*> m_effectMap;
            std::map<std::string, Mix_Music*> m_musicMap;

            bool m_isInitialized = false;
    };

}
#endif // AUDIOENGINE_H
