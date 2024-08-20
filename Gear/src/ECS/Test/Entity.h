#pragma once
#include <stdexcept>

#include "Common.h"

namespace Gear
{
    class IComponent
    {
    };

    struct Entity
    {
        uint32_t mID;
    };

    class EntityManager
    {
    public:
        Entity& CreateEntity();
        void DestroyEntity(Ref<Entity>& entity);

    private:
        std::vector<uint32_t> mEntities;
    };

    class ComponentManager
    {
    public:
        template <typename T, typename... Args>
        T& AddComponent(Ref<Entity>& entity, Args&&... args);

        template <typename T>
        void RemoveComponent(Ref<Entity>& entity);

        template <typename T>
        T& GetComponent(Ref<Entity>& entity);

        template <typename T>
        bool HasComponent(Ref<Entity>& entity);
        template <class T>
        std::vector<Ref<T>>& GetAllComponents();

    private:
        std::unordered_map<Ref<Entity>, std::unordered_map<std::type_index, Ref<IComponent>>> mComponents;
        std::unordered_map<std::type_index, std::vector<Ref<IComponent>>> mComponentPools;
    };

    template <typename T, typename... Args>
    T& ComponentManager::AddComponent(Ref<Entity>& entity, Args&&... args)
    {
        auto& componentMap = mComponents[entity];
        auto component = std::make_shared<T>(std::forward<Args>(args)...);
        componentMap[typeid(T)] = component;

        auto& pool = mComponentPools[typeid(T)];
        pool.push_back(component);

        return *component;
    }

    template <typename T>
    void ComponentManager::RemoveComponent(Ref<Entity>& entity)
    {
        auto& componentMap = mComponents[entity];

        if (const auto it = componentMap.find(typeid(T)); it != componentMap.end())
        {
            componentMap.erase(it);
            auto& pool = mComponentPools[typeid(T)];
            std::erase(pool, it->second);
        }
    }

    template <typename T>
    T& ComponentManager::GetComponent(Ref<Entity>& entity)
    {
        auto& componentMap = mComponents[entity];
        if (const auto it = componentMap.find(typeid(T)); it != componentMap.end())
        {
            return *std::static_pointer_cast<T>(it->second);
        }
        throw std::runtime_error("Component not found");
    }

    template <typename T>
    bool ComponentManager::HasComponent(Ref<Entity>& entity)
    {
        if (const auto it = mComponents.find(entity); it != mComponents.end())
        {
            const auto& componentMap = it->second;
            return componentMap.contains(typeid(T));
        }

        return false;
    }

    template <typename T>
    std::vector<Ref<T>>& ComponentManager::GetAllComponents()
    {
        const std::type_index typeIdx = typeid(T);

        auto it = mComponentPools.find(typeIdx);
        if (it == mComponentPools.end())
        {
            mComponentPools[typeIdx] = std::vector<std::shared_ptr<IComponent>>();
            it = mComponentPools.find(typeIdx);
        }

        auto& pool = it->second;
        auto typedPool = reinterpret_cast<std::vector<std::shared_ptr<T>>*>(&pool);
        return *typedPool;
    }

    class ISystem
    {
    public:
        virtual ~ISystem() = default;
        virtual void Update(float deltaTime, EntityManager& entityManager, ComponentManager& componentManager) = 0;

    protected:
        template <typename... Components>
        static bool HasRequiredComponents(Ref<Entity>& entity, ComponentManager& componentManager);
    };

    template <typename... Components>
    bool ISystem::HasRequiredComponents(Ref<Entity>& entity, ComponentManager& componentManager)
    {
        return (componentManager.HasComponent<Components>(entity) && ...);
    }
}
