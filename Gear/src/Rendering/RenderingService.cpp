#include "RenderingService.h"

#include "Application.h"
#include "GearLog.h"

namespace Gear
{
    RenderingService::RenderingService()
    {
        mGraphicContext = nullptr;
    }

    void RenderingService::Init()
    {
        GEAR_INFO("Initializing RenderingService.");
        mGraphicContext = std::make_shared<GraphicContext>();
        mGraphicContext->InitBackend();
        mGraphicContext->InitWindow({"Gear Test", {1280, 720}, {0.0f, 0.0f, 0.0f, 1.0f}});
        mGraphicContext->MakeContextCurrent();
        mGraphicContext->InitOpenGLLoader();

        Application::RegisterFlag(ApplicationFlag::ClientFinished, [this] { return this->IsWindowClosed(); });
    }

    void RenderingService::Update()
    {
        //GEAR_INFO("Updating RenderingService.");
        mGraphicContext->Clear(GL_COLOR_BUFFER_BIT);
        mGraphicContext->SwapBuffers();
        mGraphicContext->PollEvents();
    }

    void RenderingService::Dispose()
    {
        GEAR_INFO("Disposing RenderingService.");
    }

    bool RenderingService::IsWindowClosed() const
    {
        return mGraphicContext->IsWindowClosed();
    }
}
