#include <Engine/Engine.hpp>

#include <Game/ECS/Systems/SpawnArchersSystem.hpp>

class ApplicationDelegate final : public Engine::ApplicationDelegate
{
public:
    ApplicationDelegate() = default;
    ~ApplicationDelegate() = default;

public:
    void OnInit(Engine::Application* app) override
    {
        app->GetContext().systems.AddAndCreateSystem<Game::SpawnArchersSystem>();

        Engine::ResourcesParser::LoadFromXMLFile(app->GetContext().fileSystem.BuildPath(Engine::DirType::Assets, "Assets.xml"), app->GetContext());

        app->GetContext().settings.isometric.startPosition = { 500, 100 };

        auto& registry = app->GetContext().scene.GetRegistry();
        
        int order = 0;

        for (int y = 0; y < 100; ++y)
        {
            for (int x = 0; x < 100; ++x)
            {
                auto entity = registry.create();
                registry.emplace<Engine::TransformComponent>(entity, Vector2{ static_cast<float>(x) * 128.f, static_cast<float>(y) * 128.f }, Vector2{}, order);
                registry.emplace<Engine::TextureComponent>(entity, "IsoTile", app->GetContext());
                ++order;
            }
        }

        {
            auto entity = registry.create();
            registry.emplace<Engine::TransformComponent>(entity, Vector2{ 0.f, 0.f }, Vector2{ 0, -64.f }, order);
            registry.emplace<Engine::TextureComponent>(entity, "Archer", app->GetContext());
            ++order;
        }

        {
            auto entity = registry.create();
            registry.emplace<Engine::TransformComponent>(entity, Vector2{ 128.f * 1, 128.f * 2 }, Vector2{ 0, -64.f}, order);
            registry.emplace<Engine::TextureComponent>(entity, "Archer", app->GetContext());
            ++order;
        }

        app->GetContext().scene.RefreshTransforms();
    }

    void OnDeinit(Engine::Application* app) override
    {
    }

    void OnKeyDown(Engine::Application* app, int key) override
    {
        const float deltaTime = app->GetContext().time.GetDeltaTime();

        if (key == KEY_A)
        {
            _cameraTarget.x -= 250.f * deltaTime;
        }
        else if (key == KEY_D)
        {
            _cameraTarget.x += 250.f * deltaTime;
        }
        else if (key == KEY_W)
        {
            _cameraTarget.y -= 250.f * deltaTime;
        }
        else if (key == KEY_S)
        {
            _cameraTarget.y += 250.f * deltaTime;
        }

        app->GetContext().camera.SetTarget(_cameraTarget);
    }

    void OnMouseWheelMove(Engine::Application* app, float value) override
    {
        _cameraZoom += value * app->GetContext().time.GetDeltaTime();

        if (_cameraZoom < 0.2f)
        {
            _cameraZoom = 0.2f;
        }
        else if (_cameraZoom > 0.5f)
        {
            _cameraZoom = 0.5f;
        }

        app->GetContext().camera.SetZoom(_cameraZoom);
    }

private:
    Vector2 _cameraTarget;
    float _cameraZoom = 1.f;
};

int main(int argc, char** argv)
{
    Engine::Application app;
    app.SetDelegate(std::make_unique<ApplicationDelegate>());
    app.Execute(argv);
	return 0;
}
