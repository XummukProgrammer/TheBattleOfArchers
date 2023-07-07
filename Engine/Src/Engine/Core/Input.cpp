#include "Input.hpp"

#include "raylib.h"
#include "raymath.h"

namespace Engine
{
    void Input::Init()
    {
        for (int i = 0; i < 350; ++i)
        {
            _keysStatuses[i] = InputStatus::Up;
        }
    }

    void Input::CheckEvents()
    {
        CheckKeyboardStatuses();
        CheckMouseWheelMove();
    }

    void Input::CheckKeyboardStatuses()
    {
        for (auto& status : _keysStatuses)
        {
            if (IsKeyUp(status.first))
            {
            }
            else if (IsKeyPressed(status.first))
            {
                status.second = InputStatus::Pressed;

                if (_onKeyPressedCallback)
                {
                    _onKeyPressedCallback(status.first);
                }
            }
            else if (IsKeyDown(status.first))
            {
                status.second = InputStatus::Down;

                if (_onKeyDownCallback)
                {
                    _onKeyDownCallback(status.first);
                }
            }
            else if (IsKeyReleased(status.first))
            {
                status.second = InputStatus::Released;

                if (_onKeyReleasedCallback)
                {
                    _onKeyReleasedCallback(status.first);
                }
            }
        }
    }

    void Input::CheckMouseWheelMove()
    {
        float value = GetMouseWheelMove();
        if (!FloatEquals(value, 0.f))
        {
            _onMouseWheelMoveCallback(value);
        }
    }
}
