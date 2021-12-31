#include "vertexarray.h"

namespace cesaoEngine
{
    namespace graphics
    {
        VertexArray::VertexArray()
        {
            glGenVertexArrays(1, &mArrayId);
        };
        VertexArray::~VertexArray()
        {
            for(int i = 0; i < mBuffers.size(); i++)
                delete mBuffers[i];
        };

        void VertexArray::addBuffer(Buffer *pBuffer, GLuint pIndex)
        {
            bind();

            pBuffer->bind();

            glEnableVertexAttribArray(pIndex);
            glVertexAttribPointer(pIndex,
                                  pBuffer->getComponentCount(),
                                  GL_FLOAT,
                                  GL_FALSE,
                                  0,
                                  0);

            pBuffer->unbind();
            unbind();
        };
        void VertexArray::bind() const
        {
            glBindVertexArray(mArrayId);
        };
        void VertexArray::unbind() const
        {
            glBindVertexArray(0);
        };
    }
}