#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <map>
#include "GLTexture.h"

namespace Bengine{
    class TextureCache
    {
        public:
            TextureCache();
            virtual ~TextureCache();

            GLTexture getTexture(std::string texturePath);

        protected:

        private:
            std::map<std::string, GLTexture> _textureMap;
    };
}


#endif // TEXTURECACHE_H
