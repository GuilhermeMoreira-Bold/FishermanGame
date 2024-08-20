#pragma once

#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <cstdint>


using Type = std::type_index;

template<typename T>
using Ref = std::shared_ptr<T>;