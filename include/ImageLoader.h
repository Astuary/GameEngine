#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#define GLEW_STATIC
#include "GLTexture.h"
#include "picoPNG.h"
#include<string>

namespace Bengine{
    class ImageLoader
    {
        public:
            static GLTexture loadPNG(std::string filePath);

        protected:

        private:
    };
}

#endif // IMAGELOADER_H
