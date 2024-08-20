#pragma once
#include "Common.h"

namespace Gear
{
    class GameObject;
    
    class Component
    {
    public:
        virtual ~Component();
        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDispose() = 0;
        
    private:
        Ref<GameObject> gameObject;
    };
}
