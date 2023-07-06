#include <Engine/Engine.hpp>

#include <entt/entt.hpp>

int main(int argc, char** argv)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    entt::registry registry;

    Engine::Resources resources;
    Engine::ResourcesParser::LoadFromXMLFile("D:\\Git\\TheBattleOfArchers\\Assets\\Assets.xml", resources);

    auto entity = registry.create();
    registry.emplace<Engine::TextureComponent>(entity, "Test", resources);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        Engine::DrawSystem::Run(registry);

        EndDrawing();
    }

    CloseWindow();

	return 0;
}
