#include "Window.hpp"

#include "raylib.h"

namespace Engine
{
    void Window::Create(unsigned width, unsigned height, std::string_view title)
    {
        InitWindow(width, height, title.data());
        _isCreated = true;
    }

    bool Window::IsCreated() const
    {
        return _isCreated;
    }

    void Window::Remove()
    {
        if (IsCreated())
        {
            CloseWindow();
            _isCreated = false;
        }
    }

    void Window::Execute()
    {
        if (!IsCreated())
        {
            return;
        }

        while (!WindowShouldClose())
        {
            OnUpdate();

            BeginDrawing();
            ClearBackground(RAYWHITE);
            OnDraw();
            EndDrawing();
        }
    }

    void Window::OnUpdate()
    {
        if (_onUpdateCallback)
        {
            _onUpdateCallback();
        }
    }

    void Window::OnDraw()
    {
        if (_onDrawCallback)
        {
            _onDrawCallback();
        }
    }
}
