#pragma once
#include "Common.h"
#include "ApplicationService.h"

namespace Gear
{
    enum class ApplicationFlag
    {
        ClientFinished
    };

    class Application
    {
    public:
        virtual ~Application() = default;
        static const Application* GetInstance();
        static void SetInstance(Application* app);
        static bool GetFlag(ApplicationFlag flag);
        static void RegisterFlag(ApplicationFlag flag, const std::function<bool()>& flagFunction);
        static void Init();
        static void Run();
        static void Shutdown();

        static bool DefaultClientFlag();

        
        template <typename T>
        void RegisterService() const;
        void RegisterServices() const;
        void InitializeServices() const;
        void UpdateServices() const;
        void DisposeServices() const;

        template <typename T>
        static const Ref<T>& FromService();
        
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

    private:
        std::unordered_map<ApplicationFlag, std::function<bool()>> mApplicationFlags;
        std::unordered_map<Type, Ref<ApplicationService>> mApplicationServices;
        static Application* sInstance;
    };

    template <typename T>
    void Application::RegisterService() const
    {
        Ref<ApplicationService> service = std::make_shared<T>();
        sInstance->mApplicationServices.insert({typeid(T), service});
    }

    template <typename T>
    const Ref<T>& Application::FromService()
    {
        return sInstance->mApplicationServices[typeid(T)];
    }
}
