#pragma once
#include "ApplicationService.h"
#include "Common.h"
#include "GraphicContext.h"

namespace Gear
{
    class RenderingService : public ApplicationService
    {
    public:
        RenderingService();
        void Init() override;
        void Update() override;
        void Dispose() override;

    private:
        bool IsWindowClosed() const;
        Ref<GraphicContext> mGraphicContext;
    };
}
