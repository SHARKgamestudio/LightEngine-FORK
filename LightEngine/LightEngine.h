#pragma once

#include "LightEngine.g.h"

namespace winrt::SFML::implementation
{
    struct LightEngine : LightEngineT<LightEngine>
    {
        LightEngine() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::SFML::factory_implementation
{
    struct LightEngine : LightEngineT<LightEngine, implementation::LightEngine>
    {
    };
}
