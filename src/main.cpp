#include "graphics/window.h"
#include "maths/maths.h"

int main()
{
    using namespace cesaoEngine;
    using namespace graphics;
    using namespace maths;

    Window lWindow("We got the Moves", 800, 600);

    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    vec2 lVector(1.0f, 2.0f);
    lVector.add(vec2(2.0f,5.0))
           .multiply(vec2(2.0f,5.0))
           .subtract(vec2(2.0f,5.0))
           .divide(vec2(2.0f,5.0));

    while (!lWindow.closed())
    {
        lWindow.clear();

        vec2 hypa(1.0f,1.0f);
        vec3 hypa2(2.0f,5.0f, 3.0f);
        vec4 hypa3(2.0f,3.0f, 3.0f, 4.0f);
        vec4 hypa4(2.0f,3.0f, 3.0f, 4.0f);

        mat4 position = mat4::translation(hypa2);

        std::cout << "ai meudeus 1: " << (position.mElements[0 + 3 * 4])  << std::endl;
        std::cout << "ai meudeus 2: " << (position.mElements[1 + 3 * 4])  << std::endl;
        std::cout << "ai meudeus 3: " << (position.mElements[2 + 3 * 4])  << std::endl;

        if(lWindow.isKeyPressed(GLFW_KEY_A))
        {
            std::cout<< "PQ DEUS" << std::endl;
        }

        if(lWindow.isMousePressed(GLFW_MOUSE_BUTTON_1))
        {
            std::cout<< "meu deus" << std::endl;
        }

        lWindow.getMousePos();
        
        #if 1
        glBegin(GL_QUADS);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);

        glEnd();
        #endif

        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        lWindow.update();
    }

    return 0;
}
