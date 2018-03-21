#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "TextureCache.h"
#include <string>

namespace Bengine{
    class resourceManager
    {
        public:
            static GLTexture getTexture(std::string texturePath);

        protected:

        private:
            static TextureCache _textureCache;
    };
}

#endif // RESOURCEMANAGER_H
