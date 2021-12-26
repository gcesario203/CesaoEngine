#include "shader.h"
#include "../utils/fileUtils.h"

namespace cesaoEngine
{
    namespace graphics
    {
        Shader::Shader(const char *pVertPath, const char *pFragPath)
            : mVertPath(pVertPath),
              mFragPath(pFragPath)

        {
            mShaderId = load();
        }

        Shader::~Shader()
        {
            glDeleteProgram(mShaderId);
        }

        GLuint Shader::load()
        {
            GLuint lProgram = glCreateProgram();

            GLuint lVertex = glCreateShader(GL_VERTEX_SHADER);

            GLuint lFragment = glCreateShader(GL_FRAGMENT_SHADER);

            if (validateShader(lVertex, mVertPath, "Vertex Shader Error: ") == 0)
            {
                return 0;
            }
            if (validateShader(lFragment, mFragPath, "Fragment Shader Error: ") == 0)
            {
                return 0;
            }

            glAttachShader(lProgram, lVertex);
            glAttachShader(lProgram, lFragment);

            glLinkProgram(lProgram);

            glValidateProgram(lProgram);

            glDeleteShader(lVertex);
            glDeleteShader(lProgram);

            return lProgram;
        }

        GLuint Shader::validateShader(GLuint &pShader, const char *pShaderFilePath, const char *pMessage)
        {
            const char *lShaderFileSource = readFile(pShaderFilePath).c_str();

            glShaderSource(pShader, 1, &lShaderFileSource, NULL);

            glCompileShader(pShader);

            GLint lResult;

            glGetShaderiv(pShader, GL_COMPILE_STATUS, &lResult);

            if (lResult == GL_FALSE)
            {
                GLint lLength;

                glGetShaderiv(pShader, GL_INFO_LOG_LENGTH, &lLength);

                std::vector<char> lError(lLength);

                glGetShaderInfoLog(pShader, lLength, &lLength, &lError[0]);

                std::cout << pMessage << &lError[0] << std::endl;

                glDeleteShader(pShader);

                return 0;
            }

            return 1;
        }

        void Shader::enable() const
        {
            glUseProgram(mShaderId);
        }

        void Shader::disable() const
        {
            glUseProgram(0);
        }

        void Shader::setUniformMat4(const GLchar *pName, const maths::mat4 &pMatrix)
        {
            glUniformMatrix4fv(getUniformLocation(pName), 1, GL_FALSE, pMatrix.mElements);
        };

        void Shader::setUniform1i(const GLchar *pName, int pIntNumber)
        {
            glUniform1i(getUniformLocation(pName), pIntNumber);
        };

        void Shader::setUniform1f(const GLchar *pName, float pFloatNumber)
        {
            glUniform1f(getUniformLocation(pName), pFloatNumber);
        };

        void Shader::setUniform2f(const GLchar *pName, const maths::vec2 &pVector){
            glUniform2f(getUniformLocation(pName), pVector.mX, pVector.mY);
        };

        void Shader::setUniform3f(const GLchar *pName, const maths::vec3 &pVector)
        {
            glUniform3f(getUniformLocation(pName), pVector.mX, pVector.mY, pVector.mZ);
        };

        void Shader::setUniform4f(const GLchar *pName, const maths::vec4 &pVector)
        {
            glUniform4f(getUniformLocation(pName), pVector.mX, pVector.mY, pVector.mZ, pVector.mW);
        };

        GLint Shader::getUniformLocation(const char *pName)
        {
            return glGetUniformLocation(mShaderId, pName);
        };
    }
}