#include "graphics/window.h"
#include "graphics/shader.h"
#include "maths/maths.h"

#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "graphics/buffers/vertexarray.h"

#include "graphics/renderer2d.h"
#include "graphics/simple2drenderer.h"

int main()
{
    using namespace cesaoEngine;
    using namespace graphics;
    using namespace maths;

    Window lWindow("We got the Moves", 800, 600);

    mat4 lOrtho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader lShader("src/shaders/basic.vert", "src/shaders/basic.frag");
    lShader.enable();

    lShader.setUniformMat4("pr_matrix", lOrtho);
    lShader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

    Renderable2d lSpriteA(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), lShader);
    Renderable2d lSpriteB(maths::vec3(7, 1, 0), maths::vec2(2, 3), maths::vec4(0.2f, 0, 1, 1), lShader);

    Simple2dRenderer lRenderer;

    lShader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
    lShader.setUniform4f("colour", vec4(1.0f, 1.0f, 1.0f, 1.0f));

    while (!lWindow.closed())
    {
        lWindow.clear();
        double x, y;

        lWindow.getMousePos(x, y);
        lShader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f),
                                               (float)(9.0f - y * 9.0f / 540.0f)));

        lRenderer.submit(&lSpriteA);
        lRenderer.submit(&lSpriteB);
        lRenderer.flush();

        lWindow.update();
    }

    return 0;
}
