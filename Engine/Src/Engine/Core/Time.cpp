#include "Time.hpp"

#include "raylib.h"

namespace Engine
{
    float Time::GetDeltaTime() const
    {
        return GetFrameTime();
    }
}
