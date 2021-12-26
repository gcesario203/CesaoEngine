#pragma once

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include "../maths/maths.h"

namespace cesaoEngine
{
    namespace graphics
    {
        class Shader
        {
        private:
            GLuint mShaderId;
            const char *mVertPath;
            const char *mFragPath;

        public:
            Shader(const char *pVertPath, const char *pFragPath);
            ~Shader();

            void enable() const;

            void disable() const;

            void setUniformMat4(const GLchar *pName, const maths::mat4 &pMatrix);

            void setUniform1f(const GLchar *pName, float pFloatNumber);

            void setUniform1i(const GLchar *pName, int pIntNumber);

            void setUniform2f(const GLchar *pName, const maths::vec2 &pVector);

            void setUniform3f(const GLchar *pName, const maths::vec3 &pVector);

            void setUniform4f(const GLchar *pName, const maths::vec4 &pVector);

        private:
            GLuint load();
            GLuint validateShader(GLuint &pShader, const char *pShaderFileSource, const char *pMessage);
            GLint getUniformLocation(const char *pName);
        };
    }
}