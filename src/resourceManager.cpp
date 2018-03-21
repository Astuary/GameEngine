#include "resourceManager.h"

using namespace Bengine;
TextureCache resourceManager::_textureCache;

GLTexture resourceManager::getTexture(std::string texturePath){
    return _textureCache.getTexture(texturePath);
}
