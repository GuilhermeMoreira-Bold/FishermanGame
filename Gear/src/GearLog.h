#pragma once
#include <string>
#include <format>
#include <iostream>

namespace Gear
{
#define GEAR_CORE_ASSERT(condition, message, ...) \
    do \
    { \
        if(!(condition)) { \
        std::cout << std::vformat((message), std::make_format_args(__VA_ARGS__)) << '\n'; \
        } \
    } while(false)

#define GEAR_INFO(message, ...) \
    do \
    { \
        std::cout << std::vformat((message), std::make_format_args(__VA_ARGS__)) << '\n'; \
    } while(false)
}
