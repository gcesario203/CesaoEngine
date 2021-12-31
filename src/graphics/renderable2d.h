#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "../maths/maths.h"
#include "shader.h"

namespace cesaoEngine
{
    namespace graphics
    {
        class Renderable2d
        {
        protected:
            maths::vec3 mPosition;
            maths::vec2 mSize;
            maths::vec4 mColor;

            Shader &mShader;
            VertexArray *mVertexArray;
            Buffer *mVertexBuffer;
            Buffer *mColorBuffer;
            IndexBuffer *mIndexBuffer;
        public:
            Renderable2d(maths::vec3 pPosition,
                         maths::vec2 pSize,
                         maths::vec4 pColor, 
                         Shader &pShader)
                : mPosition(pPosition),
                  mSize(pSize),
                  mColor(pColor),
                  mShader(pShader)
            {
                mVertexArray = new VertexArray();
                GLfloat lVertices[] = 
                {
                    0,0,0,
                    0, pSize.mY , 0,
                    pSize.mX, pSize.mY, 0,
                    pSize.mX, 0, 0,
                };

                GLfloat lColors[] = 
                {
                    pColor.mX, pColor.mY, pColor.mZ, pColor.mW,
                    pColor.mX, pColor.mY, pColor.mZ, pColor.mW,
                    pColor.mX, pColor.mY, pColor.mZ, pColor.mW,
                    pColor.mX, pColor.mY, pColor.mZ, pColor.mW,
                };

                mVertexArray->addBuffer(new Buffer(lVertices,3 * 4, 3), 0);
                mVertexArray->addBuffer(new Buffer(lColors,4 * 4, 4), 1);

                GLushort lIndexes[] = { 0,1,2,2,3,0 };

                mIndexBuffer = new IndexBuffer(lIndexes, 6);

            };

            ~Renderable2d()
            {
                delete mVertexArray;
                delete mIndexBuffer;
            };
            
            inline const VertexArray *getVAO() const { return mVertexArray; };
            inline const IndexBuffer *getIBO() const { return mIndexBuffer; };
            inline Shader &getShader() const { return mShader; };

            inline const maths::vec3 &getPosition() const { return mPosition; };
            inline const maths::vec2 &getSize() const { return mSize; };
            inline const maths::vec4 &getColor() const { return mColor; };
        };
    }
}