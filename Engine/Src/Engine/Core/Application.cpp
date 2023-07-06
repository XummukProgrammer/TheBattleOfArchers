#include "Application.hpp"

#include <Engine/ECS/Systems/DrawSystem.hpp>

namespace Engine
{
    void Application::Execute()
    {
        _context.window.Create(800, 600, "TheBattleOfArchers");
        _context.window.SetOnUpdateCallback(std::bind(&Application::OnUpdate, this));
        _context.window.SetOnDrawCallback(std::bind(&Application::OnDraw, this));

        OnInit();

        _context.window.Execute();

        OnDeinit();

        _context.window.Remove();
    }

    void Application::OnInit()
    {
        if (_delegate)
        {
            _delegate->OnInit(this);
        }
    }

    void Application::OnDeinit()
    {
        if (_delegate)
        {
            _delegate->OnDeinit(this);
        }
    }

    void Application::OnUpdate()
    {
    }

    void Application::OnDraw()
    {
        DrawSystem::Run(_context);
    }
}
