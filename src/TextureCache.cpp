#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

using namespace Bengine;
TextureCache::TextureCache()
{
    //ctor
}

TextureCache::~TextureCache()
{
    //dtor
}

GLTexture TextureCache::getTexture(std::string texturePath){

    //std::map<std::string, GLTexture>::iterator mit = _textureMap.find(texturePath) ;
    //look up the texture & see if its in the map
    auto mit = _textureMap.find(texturePath);

    //check if its not in map
    if (mit == _textureMap.end()){

        //load the texture
        GLTexture newTexture = ImageLoader::loadPNG(texturePath);

        //insert it into the map
        std::pair<std::string, GLTexture> newPair(texturePath, newTexture);
        _textureMap.insert(newPair);

        //_textureMap.insert(make_pair(texturePath, newTexture));

        std::cout<< "Loaded Texture!\n";

        return newTexture;
    }

    std::cout<< "Used Cache Texture!\n";

    return mit->second;
}
