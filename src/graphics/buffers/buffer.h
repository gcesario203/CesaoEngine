#pragma once

#include <GL/glew.h>

namespace cesaoEngine
{
    namespace graphics
    {
        class Buffer
        {
        private:
            GLuint mBufferId;
            GLuint mComponentCount;

        public:
            Buffer(GLfloat *pData, GLsizei pCount, GLuint pComponentCount);

            void bind() const;
            void unbind() const;

            inline GLuint getComponentCount() const { return mComponentCount; };
        };
    }
}