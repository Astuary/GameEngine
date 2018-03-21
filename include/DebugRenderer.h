#ifndef DEBUGRENDERER_H
#define DEBUGRENDERER_H

#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"
#include "GLSLProgram.h"

namespace Bengine{

    class DebugRenderer
    {
        public:
            DebugRenderer();
            virtual ~DebugRenderer();

            void init();
            void end();
            void drawBox(const glm::vec4& destRect, const Bengine::ColorRGBA8& color, float angle);
            void drawCircle(const glm::vec2& centre, const Bengine::ColorRGBA8& color, float radius);
            void render();
            void dispose();

            struct DebugVertex{
                glm::vec2 position;
                Bengine::ColorRGBA8 color;
            };

        protected:

        private:
            Bengine::GLSLProgram m_program;
            std::vector<DebugRenderer> m_verts;
            std::vector<GLuint> m_indices;
            GLuint m_vbo, m_vao, m_ibo;

    };

}
#endif // DEBUGRENDERER_H
