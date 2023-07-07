#include "IsoDrawSystem.hpp"

#include <Engine/ECS/Components/TextureComponent.hpp>
#include <Engine/ECS/Components/TransformComponent.hpp>

namespace Engine
{
    void IsoDrawSystem::Run(Context& context)
    {
        auto& registry = context.scene.GetRegistry();
        auto view = registry.view<const TransformComponent, const TextureComponent>();
        view.each([&context](entt::entity entity, const TransformComponent& transformComponent, const TextureComponent& textureComponent)
            {
                if (auto texturePtr = textureComponent.GetTexture())
                {
                    if (texturePtr)
                    {
                        Vector2 pos = context.settings.isometric.startPosition;
                        pos.x += (transformComponent.position.x - transformComponent.position.y) * 0.5f;
                        pos.y += (transformComponent.position.x + transformComponent.position.y) * 0.5f * 0.5f;
                        pos.x += transformComponent.offset.x;
                        pos.y += transformComponent.offset.y;

                        DrawTextureEx(texturePtr->GetTexture(), pos, 0.f, 1.f, WHITE);
                    }
                }
            });
    }
}
