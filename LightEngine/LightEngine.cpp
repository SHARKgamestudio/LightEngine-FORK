#include "pch.h"
#include "LightEngine.h"
#if __has_include("LightEngine.g.cpp")
#include "LightEngine.g.cpp"
#endif

namespace winrt::SFML::implementation
{
    int32_t LightEngine::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void LightEngine::MyProperty(int32_t /*value*/)
    {
        throw hresult_not_implemented();
    }
}
