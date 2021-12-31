#pragma once

#include <GL/glew.h>

namespace cesaoEngine
{
    namespace graphics
    {
        class IndexBuffer
        {
        private:
            GLuint mBufferId;
            GLuint mCount;

        public:
            IndexBuffer(GLushort *pData, GLsizei pCount);

            void bind() const;
            void unbind() const;

            inline GLuint getCount() const { return mCount; };
        };
    }
}