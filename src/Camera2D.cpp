#include "Camera2D.h"
#include <cstdlib>
namespace Bengine{

    Camera2D::Camera2D(): _screenWidth(500),
        _screenHeight(500),
        _needsMatrixUpdate(true),
        _position(0.0f, 0.0f),
        _cameraMatrix(1.0f),
        _scale(1.0f),
        _orthoMatrix(1.0f)
    {
        //ctor
    }

    Camera2D::~Camera2D()
    {
        //dtor
    }

    void Camera2D::init(int screenWidth, int screenHeight){
        _screenHeight = screenHeight;
        _screenWidth = screenWidth;
        _orthoMatrix = glm::ortho(0.0f, (float)_screenWidth,0.0f ,(float)_screenHeight);
    }

    void Camera2D::update(){

        if(_needsMatrixUpdate){
            glm::vec3 translate (- _position.x + _screenWidth/2, - _position.y + _screenHeight/2, 0.0f);
            _cameraMatrix = glm::translate(_orthoMatrix, translate);

            glm::vec3 scale (_scale, _scale, 0.0f);
            _cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;

            /*translate = glm::vec3(_screenWidth/2, _screenHeight/2, 0.0f);
            _cameraMatrix = glm::translate(_cameraMatrix, translate);*/

            _needsMatrixUpdate = false;
        }

    }

    glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords){
        //Invert Y direction
        screenCoords.y = _screenHeight - screenCoords.y;

        //0 is the center
        screenCoords -= glm::vec2(_screenWidth/2, _screenHeight/2);
        screenCoords /= _scale; // scale the coords

        //Translate with camera position
        screenCoords += _position;
        return screenCoords;
    }

    ///camera culling
    bool Camera2D::isBoxInView(const glm::vec2& position, const glm::vec2& dimensions){

        glm::vec2 scaledScreenDimensions = glm::vec2(_screenWidth, _screenHeight) / (_scale);

        const float MIN_DISTANCE_X = (dimensions.x / 2.0f) + (scaledScreenDimensions.x / 2.0f);
        const float MIN_DISTANCE_Y = (dimensions.y / 2.0f) + (scaledScreenDimensions.y / 2.0f);

        glm::vec2 centerPos = position + (dimensions / 2.0f);
        glm::vec2 centerCameraPos = _position; //+ glm::vec2(scaledScreenDimensions.x / 2.0f, scaledScreenDimensions.y / 2.0f);
        glm::vec2 distVec = centerPos - centerCameraPos;

        float xdepth = MIN_DISTANCE_X - abs(distVec.x);
        float ydepth = MIN_DISTANCE_Y - abs(distVec.y);

        if(xdepth > 0 && ydepth > 0){
            ///there was a collision
            return true;
        }
        return false;
    }

}
