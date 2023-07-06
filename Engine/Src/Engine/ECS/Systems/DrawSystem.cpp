#include "DrawSystem.hpp"

#include <Engine/ECS/Components/TextureComponent.hpp>

#include "raylib.h"

namespace Engine
{
    void DrawSystem::Run(Context& context)
    {
        auto view = context.registry.view<const TextureComponent>();
        view.each([](entt::entity entity, const TextureComponent& textureComponent)
            {
                if (auto texturePtr = textureComponent.GetTexture())
                {
                    if (texturePtr)
                    {
                        DrawTexture(texturePtr->GetTexture().value(), 0, 0, WHITE);
                    }
                }
            });
    }
}
