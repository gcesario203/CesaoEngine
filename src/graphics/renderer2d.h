#pragma once


#include <GL/glew.h>
#include "../maths/maths.h"
#include "renderable2d.h"

namespace cesaoEngine
{
    namespace graphics
    {
        class Renderer2d
        {
        public:
            virtual void submit(const Renderable2d *pRenderable) = 0;
            virtual void flush() = 0;
        };
    }
}