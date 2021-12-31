

#include "simple2drenderer.h"

namespace cesaoEngine
{
    namespace graphics
    {

        void Simple2dRenderer::submit(const Renderable2d *pRenderable)
        {
            mRenderQueue.push_back(pRenderable);
        };
        void Simple2dRenderer::flush()
        {
            while (!mRenderQueue.empty())
            {
                const Renderable2d* lRenderable = mRenderQueue.front();

                lRenderable->getVAO()->bind();
                lRenderable->getIBO()->bind();

                lRenderable->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(lRenderable->getPosition()));

                glDrawElements( GL_TRIANGLES, lRenderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
                lRenderable->getIBO()->unbind();
                lRenderable->getVAO()->unbind();

                mRenderQueue.pop_front();
            }
            
        };
    }
}