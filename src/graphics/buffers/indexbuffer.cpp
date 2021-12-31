#include "indexbuffer.h"

namespace cesaoEngine
{
    namespace graphics
    {
        IndexBuffer::IndexBuffer(GLushort *pData, GLsizei pCount)
            : mCount(pCount)
        {
            glGenBuffers(1, &mBufferId);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);

            glBufferData(GL_ELEMENT_ARRAY_BUFFER, pCount * sizeof(GLushort), pData, GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void IndexBuffer::bind() const
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
        }

        void IndexBuffer::unbind() const
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    }
}