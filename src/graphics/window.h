#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace cesaoEngine
{
    namespace graphics
    {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

        void window_resize(GLFWwindow *pWindow, int pWidth, int pHeight);

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

            inline int getWidth() const { return mWidth; }
            inline int getHeight() const { return mHeight; }

            bool isKeyPressed(unsigned int pKeyCode) const;
            bool isMousePressed(unsigned int pButton) const;

            void getMousePos(double &pX, double &pY) const;

            bool mKeys[MAX_KEYS];
            bool mMouseButtons[MAX_BUTTONS];
            // double mX, mY;
            double mX, mY;

        private:
            bool init();

            static void key_callback(GLFWwindow *pWindow, int pKey, int pScanCode, int pAction, int pMods);
            static void mouse_button_callback(GLFWwindow *pWindow, int pButton, int pAction, int pMods);
            static void cursor_position_callback(GLFWwindow *pWindow, double pXpos, double pYpos);
        };

    }

}