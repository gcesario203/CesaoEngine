#pragma once

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace cesaoEngine
{
    namespace graphics
    {
        class VertexArray
        {
            private:
                GLuint mArrayId;
                std::vector<Buffer*> mBuffers;
            public:
                VertexArray();
                ~VertexArray();

                void addBuffer(Buffer *pBuffer, GLuint pIndex);
                void bind() const;
                void unbind() const;
        };
    }
}