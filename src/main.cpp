#include "graphics/window.h"
#include "graphics/shader.h"
#include "maths/maths.h"

int main()
{
    using namespace cesaoEngine;
    using namespace graphics;
    using namespace maths;

    Window lWindow("We got the Moves", 800, 600);

    glClearColor(1.2f, 0.3f, 0.8f, 1.0f);

    GLfloat lVertices[] =
        {
            0,
            0,
            0,
            8,
            0,
            0,
            0,
            3,
            0,
            0,
            3,
            0,
            8,
            3,
            0,
            8,
            0,
            0,
        };

    GLushort lIndexes[] = {
        0,1,2,
        2,3,0
    };

    GLuint lVbo, lVao;
    glGenVertexArrays(1, &lVao);
    glBindVertexArray(lVao);
    glGenBuffers(1, &lVbo);
    glBindBuffer(GL_ARRAY_BUFFER, lVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lVertices), lVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    mat4 lOrtho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader lShader("src/shaders/basic.vert", "src/shaders/basic.frag");
    lShader.enable();

    lShader.setUniformMat4("pr_matrix", lOrtho);
    lShader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

    lShader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
    lShader.setUniform4f("colour", vec4(1.0f, 1.0f, 1.0f, 1.0f));

    while (!lWindow.closed())
    {
        lWindow.clear();
        double x, y;

        lWindow.getMousePos(x, y);
        lShader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f),
                                                (float)(9.0f - y * 9.0f / 540.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // glDrawElements(GL_TRIANGLES, ib)
        lWindow.update();
    }

    return 0;
}
