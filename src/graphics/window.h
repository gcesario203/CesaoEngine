#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace cesaoEngine
{
    namespace graphics
    {

        void windowResize(GLFWwindow *pWindow, int pWidth, int pHeight);

        class Window
        {
        private:
            const char *mTitle;
            int mWidth, mHeight;
            GLFWwindow *mWindow;
            bool mClosed;
        public:
            Window(const char *pTitle, int pWidth, int pHeight);
            ~Window();

            void update();
            bool closed() const;
            void clear() const;

            inline int getWidth() const { return mWidth ;}
            inline int getHeight() const { return mHeight ;}
        private:
            bool init();
        };
    }
}