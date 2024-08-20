#include "GraphicContext.h"

#include <GLFW/glfw3.h>

#include "GearLog.h"

namespace Gear
{
    GraphicContext::GraphicContext()
    {
        mWindow = nullptr;
    }

    void GraphicContext::InitWindow(const WindowProps& props)
    {
        mWindow = std::make_shared<Window>(props);
        mWindow->Init();
    }

    void GraphicContext::MakeContextCurrent() const
    {
        mWindow->MakeContextCurrent();
    }

    void GraphicContext::InitBackend()
    {
        GEAR_CORE_ASSERT(glfwInit(), "Could not initialize GLFW.");
    }

    void GraphicContext::InitOpenGLLoader()
    {
        GEAR_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress),
                         "OpenGL drivers not found.");

        GEAR_INFO("OpenGL drivers loaded.");
    }

    void GraphicContext::SetClearColor(const Color& clearColor) const
    {
        mWindow->SetClearColor(clearColor);
    }

    void GraphicContext::Clear(int bitMask) const
    {
        mWindow->Clear(bitMask);
    }

    void GraphicContext::PollEvents() const
    {
        mWindow->PollEvents();
    }

    void GraphicContext::SwapBuffers() const
    {
        mWindow->SwapBuffers();
    }

    bool GraphicContext::IsWindowClosed() const
    {
        return mWindow->IsClosed();
    }
}
