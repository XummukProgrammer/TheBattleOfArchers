#include <Engine/Engine.hpp>

int main(int argc, char** argv)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    Engine::Resources resources;
    Engine::ResourcesParser::LoadFromXMLFile("D:\\Git\\TheBattleOfArchers\\Assets\\Assets.xml", resources);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawTexture(resources.GetResource<Engine::ResourceTexture>("Test")->GetTexture().value(), 0, 0, WHITE);

        EndDrawing();
    }

    CloseWindow();

	return 0;
}
