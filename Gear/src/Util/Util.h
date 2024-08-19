#pragma once
#include <string>

namespace Gear
{
    struct Size
    {
        int width;
        int height;
    };

    struct Color
    {
        float r;
        float g;
        float b;
        float a;
    };

    struct WindowProps
    {
        const std::string& title;
        const Size& size;
        const Color& clearColor;
    };
}
