#pragma once
#include "Common.h"
#include "Window.h"
#include "Util/Util.h"

namespace Gear
{
    class GraphicContext
    {
    public:
        GraphicContext();
        void InitWindow(const WindowProps& props);
        void MakeContextCurrent() const;
        static void InitBackend();
        static void InitOpenGLLoader();
        void SetClearColor(const Color& clearColor) const;
        void Clear(int bitMask) const;
        void PollEvents() const;
        void SwapBuffers() const;
        bool IsWindowClosed() const;

    private:
        Ref<Window> mWindow;
    };

}
