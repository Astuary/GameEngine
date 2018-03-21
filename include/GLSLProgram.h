#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#define GLEW_STATIC
#include <string>
#include <iostream>
#include <GL/glew.h>
using namespace std;

namespace Bengine{
    class GLSLProgram
    {
        public:
            GLSLProgram();
            ~GLSLProgram();

            void compileShaders(const string &vertexShaderFileName, const string &fragmentShaderFilePath);
            void compileShadersFromSource(const char* vertexSource, const char* fragmentSource);
            void linkShaders();
            void addAttribute(const string &attributeName);
            GLint getUniformLocation(const string& uniformName);
            void use();
            void unuse();

        protected:

        private:
            int _numAttributes;
            GLuint _programID;
            GLuint _vertexShaderID;
            GLuint _fragmentShaderID;

            void compileShader(const char* source, const std::string& name, GLuint id);
    };

}
#endif // GLSLPROGRAM_H
