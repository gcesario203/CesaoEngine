#pragma once

#include <deque>
#include "renderer2d.h"

namespace cesaoEngine
{
    namespace graphics
    {
        class Simple2dRenderer : public Renderer2d
        {
        private:
            std::deque<const Renderable2d*> mRenderQueue;
        public:
            void submit(const Renderable2d *pRenderable) override;
            void flush() override;
        };
    }
}