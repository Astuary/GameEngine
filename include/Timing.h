#ifndef TIMING_H
#define TIMING_H

namespace Bengine{

    class FpsLimiter{
    public:
        FpsLimiter();
        void init(float maxFPS);

        void setMaxFPS(float maxFPS);

        void begin();
        float end(); //returns current FPS

    private:
        void calculateFPS();

        float _maxFPS;
        unsigned int _startTicks;
        float _fps;
        float _frameTime;
        //float _maxFPS;
    };

}

#endif // TIMING_H
