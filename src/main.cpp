#include "graphics/window.h"

int main()
{
    using namespace cesaoEngine;
    using namespace graphics;

    Window lWindow("We got the Moves", 800, 600);

    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while (!lWindow.closed())
    {
        lWindow.clear();

        if(lWindow.isKeyPressed(GLFW_KEY_A))
        {
            std::cout<< "PQ DEUS" << std::endl;
        }

        if(lWindow.isMousePressed(GLFW_MOUSE_BUTTON_1))
        {
            std::cout<< "meu deus" << std::endl;
        }

        lWindow.getMousePos();
        
        #if 0
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
