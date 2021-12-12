#include "window.h"

namespace cesaoEngine
{
    namespace graphics
    {
        Window::Window(const char *pTitle, int pWidth, int pHeight)
        {
            mTitle = pTitle;
            mWidth = pWidth;
            mHeight = pHeight;

            if (!init())
                glfwTerminate();
        }

        Window::~Window()
        {
            glfwTerminate();
        }

        bool Window::init()
        {
            if (!glfwInit())
            {
                std::cout << "Failed to Init GLFW Window" << std::endl;

                return false;
            }

            mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);

            if (!mWindow)
            {
                glfwTerminate();
                std::cout << "Failed to Create GLFW Window" << std::endl;
                return false;
            }

            glfwMakeContextCurrent(mWindow);

            glfwSetWindowSizeCallback(mWindow, windowResize);

            if (glewInit() != GLEW_OK)
            {
                std::cout << "DEU RUIM NO GLEW" << std::endl;
                return false;
            }

            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

            return true;
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(mWindow) == 1;
        }

        void Window::update()
        {

            glfwSwapBuffers(mWindow);
            glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);

            windowResize(mWindow, mWidth, mHeight);
            glfwPollEvents();
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void windowResize(GLFWwindow *pWindow, int pWidth, int pHeight)
        {
            glViewport(0, 0, pWidth, pHeight);
        }
    }
}