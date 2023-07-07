#include "Application.hpp"

#include <Engine/ECS/Systems/IsoDrawSystem.hpp>

namespace Engine
{
    void Application::Execute(char** argv)
    {
        _context.window.Create(1280, 720, "TheBattleOfArchers");
        _context.window.SetOnUpdateCallback(std::bind(&Application::OnUpdate, this));
        _context.window.SetOnDrawCallback(std::bind(&Application::OnDraw, this));

        _context.fileSystem.Init(argv);

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
        IsoDrawSystem::Run(_context);
    }
}
