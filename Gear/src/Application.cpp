#include "Application.h"

#include "GearLog.h"
#include "BooleanLabels.h"

#include "ObjectPoolService.h"
#include "Rendering/RenderingService.h"

namespace Gear
{
    Application* Application::sInstance;
    
    const Application* Application::GetInstance()
    {
        return sInstance;
    }

    void Application::SetInstance(Application* app)
    {
        sInstance = app;
    }

    void Application::Init()
    {
        GEAR_CORE_ASSERT(sInstance, "Client application is null {}.");

        RegisterFlag(ApplicationFlag::ClientFinished, DefaultClientFlag);
        sInstance->RegisterServices();
        sInstance->InitializeServices();
        sInstance->Start();
    }

    bool Application::GetFlag(const ApplicationFlag flag)
    {
        const std::function<bool()>& flagFunction = sInstance->mApplicationFlags[flag];
        GEAR_CORE_ASSERT(flagFunction, "The {} is not defined.", FlagToString(flag));

        return flagFunction();
    }

    void Application::RegisterFlag(ApplicationFlag flag, const std::function<bool()>& flagFunction)
    {
        sInstance->mApplicationFlags[flag] = flagFunction;
    }

    void Application::Run()
    {
        while (NOT(sInstance->GetFlag(ApplicationFlag::ClientFinished)))
        {
            sInstance->UpdateServices();
            sInstance->Update();
        }
    }

    void Application::Shutdown()
    {
        sInstance->Dispose();
        sInstance->DisposeServices();

        delete sInstance;
    }

    bool Application::DefaultClientFlag()
    {
        return false;
    }

    void Application::RegisterServices() const
    {
        RegisterService<RenderingService>();
        RegisterService<ObjectPoolService>();
    }

    void Application::InitializeServices() const
    {
        for (const auto& service : mApplicationServices)
        {
            service.second->Init();
        }
    }

    void Application::UpdateServices() const
    {
        for (const auto& service : mApplicationServices)
        {
            service.second->Update();
        }
    }

    void Application::DisposeServices() const
    {
        for (const auto& service : mApplicationServices)
        {
            service.second->Dispose();
        }
    }
}
