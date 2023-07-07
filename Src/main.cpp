#include <Engine/Engine.hpp>

#include <Engine/ECS/Systems/IsoDrawSystem.hpp>

class ApplicationDelegate final : public Engine::ApplicationDelegate
{
public:
    ApplicationDelegate() = default;
    ~ApplicationDelegate() = default;

public:
    void OnInit(Engine::Application* application) override
    {
        Engine::ResourcesParser::LoadFromXMLFile(application->GetContext().fileSystem.BuildPath(Engine::DirType::Assets, "Assets.xml"), application->GetContext());

        application->GetContext().settings.isometric.startPosition = { 500, 100 };

        auto& registry = application->GetContext().scene.GetRegistry();
        
        int order = 0;

        for (int y = 0; y < 3; ++y)
        {
            for (int x = 0; x < 2; ++x)
            {
                auto entity = registry.create();
                registry.emplace<Engine::TransformComponent>(entity, Vector2{ static_cast<float>(x) * 128.f, static_cast<float>(y) * 128.f }, Vector2{}, order);
                registry.emplace<Engine::TextureComponent>(entity, "IsoTile", application->GetContext());
                ++order;
            }
        }

        {
            auto entity = registry.create();
            registry.emplace<Engine::TransformComponent>(entity, Vector2{ 0.f, 0.f }, Vector2{ 0, -64.f }, order);
            registry.emplace<Engine::TextureComponent>(entity, "Archer", application->GetContext());
            ++order;
        }

        {
            auto entity = registry.create();
            registry.emplace<Engine::TransformComponent>(entity, Vector2{ 128.f * 1, 128.f * 2 }, Vector2{ 0, -64.f}, order);
            registry.emplace<Engine::TextureComponent>(entity, "Archer", application->GetContext());
            ++order;
        }
    }

    void OnDeinit(Engine::Application* application) override
    {
    }
};

int main(int argc, char** argv)
{
    Engine::Application app;
    app.SetDelegate(std::make_unique<ApplicationDelegate>());
    app.Execute(argv);
	return 0;
}
