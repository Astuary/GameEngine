#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <GL/glew.h>

namespace Bengine{
    struct GLTexture{
        GLuint id;
        int width;
        int height;
    };
}
#endif // GLTEXTURE_H
