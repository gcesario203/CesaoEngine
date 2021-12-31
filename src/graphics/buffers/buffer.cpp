#include "buffer.h"

namespace cesaoEngine
{
    namespace graphics
    {
        Buffer::Buffer(GLfloat *pData, GLsizei pCount, GLuint pComponentCount)
            : mComponentCount(pComponentCount)
        {
            glGenBuffers(1, &mBufferId);

            glBindBuffer(GL_ARRAY_BUFFER, mBufferId);

            glBufferData(GL_ARRAY_BUFFER, pCount * sizeof(GLfloat), pData, GL_STATIC_DRAW);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void Buffer::bind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, mBufferId);
        }

        void Buffer::unbind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    }
}