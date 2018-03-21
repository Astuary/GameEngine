#ifndef PARTICLEENGINE2D_H
#define PARTICLEENGINE2D_H

#include <vector>

namespace Bengine{

    class ParticleBatch2D;
    class SpriteBatch;

    class ParticleEngine2D
    {
        public:
            ParticleEngine2D();
            virtual ~ParticleEngine2D();

            void addParticleBatch(ParticleBatch2D* particleBatch);///after adding a particle batch, the engine becomes resp for dealloc
            void update(float deltaTime);
            void draw(SpriteBatch* spriteBatch);

        protected:

        private:
            std::vector<ParticleBatch2D* > m_batches;
    };
}
#endif // PARTICLEENGINE2D_H
