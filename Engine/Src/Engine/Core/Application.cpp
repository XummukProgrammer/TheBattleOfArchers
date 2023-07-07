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
        _context.camera.Init();

        _context.input.Init();
        _context.input.SetOnKeyPressedCallback(std::bind(&Application::OnKeyPressed, this, std::placeholders::_1));
        _context.input.SetOnKeyDownCallback(std::bind(&Application::OnKeyDown, this, std::placeholders::_1));
        _context.input.SetOnKeyReleasedCallback(std::bind(&Application::OnKeyReleased, this, std::placeholders::_1));
        _context.input.SetOnMouseWheelMoveCallback(std::bind(&Application::OnMouseWheelMove, this, std::placeholders::_1));

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
        _context.input.CheckEvents();
    }

    void Application::OnDraw()
    {
        _context.camera.BeginMode();
        IsoDrawSystem::Run(_context);
        _context.camera.EndMode();
    }

    void Application::OnKeyPressed(int key)
    {
        if (_delegate)
        {
            _delegate->OnKeyPressed(this, key);
        }
    }

    void Application::OnKeyDown(int key)
    {
        if (_delegate)
        {
            _delegate->OnKeyDown(this, key);
        }
    }

    void Application::OnKeyReleased(int key)
    {
        if (_delegate)
        {
            _delegate->OnKeyReleased(this, key);
        }
    }

    void Application::OnMouseWheelMove(float value)
    {
        if (_delegate)
        {
            _delegate->OnMouseWheelMove(this, value);
        }
    }
}
