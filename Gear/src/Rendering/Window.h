#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Util/Util.h"

namespace Gear
{
    class Window
    {
    public:
        Window();
        Window(const WindowProps& props);
        void Init();
        void MakeContextCurrent() const;
        void SetClearColor(const Color& clearColor);
        static void Clear(int bitMask);
        static void PollEvents();
        void SwapBuffers() const;
        bool IsClosed() const;

    private:
        Color mClearColor;
        Size mSize;
        std::string mTitle;
        GLFWwindow* mNativeWindowPtr;
    };
}
