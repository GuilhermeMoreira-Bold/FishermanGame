#pragma once

#include "Common.h"
#include "Component.h"
#include "Container.h"

namespace Gear
{
    class ComponentContainer : public Container<Component>
    {
    public:
        template <typename T, typename... Args>
        Ref<T> AddComponent(Args&&... args);

        template <typename T>
        Ref<T> GetComponent();

        template <typename T>
        Ref<T> RemoveComponent();
    };

    template <typename T, typename... Args>
    Ref<T> ComponentContainer::AddComponent(Args&&... args)
    {
        Ref<Component> component = std::make_shared<T>(std::forward<Args>(args)...);
        mElements[typeid(T)] = component;
        return component;
    }

    template <typename T>
    Ref<T> ComponentContainer::GetComponent()
    {
        return mElements[typeid(T)];
    }

    template <typename T>
    Ref<T> ComponentContainer::RemoveComponent()
    {
        Ref<Component> component = mElements[typeid(T)];
        mElements.erase(typeid(T));
        return component;
    }
}
