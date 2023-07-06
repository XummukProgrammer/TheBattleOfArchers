#include <Engine/Engine.hpp>

class ApplicationDelegate final : public Engine::ApplicationDelegate
{
public:
    ApplicationDelegate() = default;
    ~ApplicationDelegate() = default;

public:
    void OnInit(Engine::Application* application) override
    {
        Engine::ResourcesParser::LoadFromXMLFile("D:\\Git\\TheBattleOfArchers\\Assets\\Assets.xml", application->GetContext());

        auto& registry = application->GetContext().scene.GetRegistry();
        auto entity = registry.create();
        registry.emplace<Engine::TextureComponent>(entity, "Test", application->GetContext());
    }

    void OnDeinit(Engine::Application* application) override
    {
    }
};

int main(int argc, char** argv)
{
    Engine::Application app;
    app.SetDelegate(std::make_unique<ApplicationDelegate>());
    app.Execute();
	return 0;
}
