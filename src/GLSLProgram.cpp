#include "GLSLProgram.h"
#include "errors.h"
#include "IOManager.h"

#include <fstream>
#include <vector>

namespace Bengine{
    GLSLProgram::GLSLProgram() : _numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
    {
        //ctor
    }

    GLSLProgram::~GLSLProgram()
    {
        //dtor
    }

    void GLSLProgram::compileShaders(const string &vertexShaderFileName, const string &fragmentShaderFilePath){

        std::string fragSource, vertSource;

        IOManager::readFileToBuffer(vertexShaderFileName, vertSource);
        IOManager::readFileToBuffer(fragmentShaderFilePath, fragSource);

        compileShadersFromSource(vertSource.c_str(), fragSource.c_str());

    }

    void GLSLProgram::compileShadersFromSource(const char* vertexSource, const char* fragmentSource){

        _programID = glCreateProgram();
        _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

        if(_vertexShaderID == 0){
            fatalError("Vertex Shader failed to be created!");
        }

        _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        if(_fragmentShaderID == 0){
            fatalError("Fragment Shader failed to be created!");
        }

        compileShader(vertexSource, "Vertex Shader", _vertexShaderID);
        compileShader(fragmentSource, "Fragment Shader", _fragmentShaderID);
    }

    void GLSLProgram::linkShaders(){

        //Attach our shaders to our program
        glAttachShader(_programID, _vertexShaderID);
        glAttachShader(_programID, _fragmentShaderID);

        //Link our program
        glLinkProgram(_programID);

        //Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
        if(isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL character
            vector<char> infoLog(maxLength);
            glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);

            //We don't need the program anymore.
            glDeleteProgram(_programID);
            //Don't leak shaders either.
            glDeleteShader(_vertexShaderID);
            glDeleteShader(_fragmentShaderID);

            //Use the infoLog as you see fit.

            printf("%s\n", &(infoLog[0]));
            fatalError("Shader failed to link.");

            //In this simple program, we'll just leave
            return;
        }

        //Always detach shaders after a successful link.
        glDetachShader(_programID, _vertexShaderID);
        glDetachShader(_programID, _fragmentShaderID);

        glDeleteShader(_vertexShaderID);
        glDeleteShader(_fragmentShaderID);

    }

    void GLSLProgram::addAttribute(const string &attributeName){
        glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
    }

    GLint GLSLProgram::getUniformLocation(const string& uniformName){
        GLint location = glGetUniformLocation(_programID, uniformName.c_str());
        if(location == GL_INVALID_INDEX){
            fatalError("Uniform " + uniformName + " not found in shader!");
        }
        return location;
    }

    void GLSLProgram::use(){
        glUseProgram(_programID);
        for(int i=0; i<_numAttributes; i++){
            glEnableVertexAttribArray(i);
        }
    }

    void GLSLProgram::unuse(){
        glUseProgram(0);
        for(int i=0; i<_numAttributes; i++){
            glDisableVertexAttribArray(i);
        }
    }

    void GLSLProgram::compileShader(const char* source, const std::string& name, GLuint id){

        /*ifstream vertexFile(filePath);
        if(vertexFile.fail()){
            perror(filePath.c_str());
            fatalError("Failed to open " + filePath);
        }

        string fileContents = "";
        string line;

        while(getline(vertexFile, line)){
            fileContents += line + "\n";
        }

        vertexFile.close();

        const char* contentsPtr = fileContents.c_str();
        glShaderSource(id, 1, &contentsPtr, nullptr);*/
        glShaderSource(id, 1, &source, nullptr);

        glCompileShader(id);

        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if(success == GL_FALSE){

            GLint maxLength = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
            vector<char> errorLog(maxLength);
            glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
            glDeleteShader(id);

            printf("%s\n", &(errorLog[0]));
            fatalError("Shader " + name + " failed to compile.");

        }
    }

}








