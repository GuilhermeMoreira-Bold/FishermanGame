#pragma once

#include "Common.h"

namespace Gear
{
    template <typename Base>
    class Container
    {
    public:
        const std::unordered_map<std::type_index, Ref<Base>>& GetElements();
        
    protected:
        std::unordered_map<std::type_index, Ref<Base>> mElements;
    };

    template <typename Base>
    const std::unordered_map<std::type_index, Ref<Base>>& Container<Base>::GetElements()
    {
        return mElements;
    }
}
