#pragma once
#include "ECS/Test/Entity.h"

namespace Gear
{
    class SpriteSystem : public ISystem
    {
    public:
        void Update(float deltaTime, EntityManager& entityManager, ComponentManager& componentManager) override;
    };

}
