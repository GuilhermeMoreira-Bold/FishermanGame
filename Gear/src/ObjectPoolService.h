#pragma once
#include "ApplicationService.h"

namespace Gear
{
    class ObjectPoolService : public ApplicationService
    {
    public:
        void Init() override;
        void Update() override;
        void Dispose() override;
    };
}
