#include "Window.h"
#include "GearLog.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Gear
{
    Window::Window()
    {
        mSize = {1280, 720};
        mTitle = "Gear Window";
        mClearColor = {0.0f, 0.0f, 0.0f, 1.0f};
        mNativeWindowPtr = nullptr;
    }

    Window::Window(const WindowProps& props)
    {
        mSize = props.size;
        mTitle = props.title;
        mClearColor = props.clearColor;
        mNativeWindowPtr = nullptr;
    }

    void Window::Init()
    {
        mNativeWindowPtr = glfwCreateWindow(mSize.width, mSize.height, mTitle.c_str(), nullptr, nullptr);
        GEAR_CORE_ASSERT(mNativeWindowPtr, "Could not create GLFW window.");
    }

    void Window::MakeContextCurrent() const
    {
        glfwMakeContextCurrent(mNativeWindowPtr);
    }

    void Window::SetClearColor(const Color& clearColor)
    {
        mClearColor = clearColor;
    }

    void Window::Clear(const int bitMask)
    {
        glClear(bitMask);
    }

    void Window::PollEvents()
    {
        glfwPollEvents();
    }

    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(mNativeWindowPtr);
    }

    bool Window::IsClosed() const
    {
        return glfwWindowShouldClose(mNativeWindowPtr);
    }
}
