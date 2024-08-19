#pragma once
namespace Gear
{
    class ApplicationService
    {
    public:
        virtual ~ApplicationService() = default;

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;
    };
}
