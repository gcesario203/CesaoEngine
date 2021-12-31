#include "window.h"

namespace cesaoEngine
{
    namespace graphics
    {
        // bool Window::mKeys[MAX_KEYS];
        // bool Window::mMouseButtons[MAX_BUTTONS];

        // double Window::mX;
        // double Window::mY;
        
        Window::Window(const char *pTitle, int pWidth, int pHeight)
        {
            mTitle = pTitle;
            mWidth = pWidth;
            mHeight = pHeight;

            if (!init())
                glfwTerminate();

            for (int i = 0; i < MAX_KEYS; i++)
            {
                mKeys[i] = false;
            }
            for (int i = 0; i < MAX_BUTTONS; i++)
            {
                mMouseButtons[i] = false;
            }
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
            glfwSetWindowUserPointer(mWindow, this);
            glfwSetWindowSizeCallback(mWindow, window_resize); 
            glfwSetKeyCallback(mWindow, key_callback);
            glfwSetMouseButtonCallback(mWindow, mouse_button_callback);
            glfwSetCursorPosCallback(mWindow, cursor_position_callback);

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

            window_resize(mWindow, mWidth, mHeight);
            glfwPollEvents();
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void window_resize(GLFWwindow *pWindow, int pWidth, int pHeight)
        {
            glViewport(0, 0, pWidth, pHeight);
        }

        void Window::key_callback(GLFWwindow *pWindow, int pKey, int pScanCode, int pAction, int pMods)
        {
            Window *lWindow = (Window *)glfwGetWindowUserPointer(pWindow);

            lWindow->mKeys[pKey] = pAction != GLFW_RELEASE;
        }
        
        void Window::mouse_button_callback(GLFWwindow *pWindow, int pButton, int pAction, int pMods)
        {
            Window *lWindow = (Window *)glfwGetWindowUserPointer(pWindow);

            lWindow->mMouseButtons[pButton] = pAction != GLFW_RELEASE;
        }
        void Window::cursor_position_callback(GLFWwindow *pWindow, double pXpos, double pYpos)
        {
            Window *lWindow = (Window *)glfwGetWindowUserPointer(pWindow);

            lWindow->mX = pXpos;
            lWindow->mY = pYpos;
        }

        bool Window::isKeyPressed(unsigned int pKeyCode) const
        {
            if (pKeyCode > MAX_KEYS)
            {
                return false;
            }
            else
            {
                return mKeys[pKeyCode];
            }
        }
        bool Window::isMousePressed(unsigned int pButton) const
        {
            if (pButton > MAX_BUTTONS)
            {
                return false;
            }
            else
            {
                return mMouseButtons[pButton];
            }
        }

        void Window::getMousePos(double &pX, double &pY) const
        {
            pX = mX;
            pY = mY;
        }
    }
}