#pragma once
#include "Gear.h"

namespace FishmanLife
{
    class Sandbox : public Gear::Application
    {
    public:
        void Start() override;
        void Update() override;
        void Dispose() override;
    };
}
