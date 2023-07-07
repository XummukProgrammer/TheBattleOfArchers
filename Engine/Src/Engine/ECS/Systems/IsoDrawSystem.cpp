#include "IsoDrawSystem.hpp"

#include <Engine/ECS/Components/TextureComponent.hpp>
#include <Engine/ECS/Components/TransformComponent.hpp>

namespace Engine
{
    void IsoDrawSystem::Run(Context& context)
    {
        auto& registry = context.scene.GetRegistry();

        registry.sort<TransformComponent>([](const TransformComponent& left, const TransformComponent& right)
            {
                if (left.positionY == right.positionY)
                {
                    return left.positionX < right.positionX;
                }
                return left.positionY < right.positionY;
            });

        auto view = registry.view<const TransformComponent, const TextureComponent>();
        view.each([](entt::entity entity, const TransformComponent& transformComponent, const TextureComponent& textureComponent)
            {
                if (auto texturePtr = textureComponent.GetTexture())
                {
                    if (texturePtr)
                    {
                        Vector2 pos = { 500.f, 100.f };
                        pos.x += (transformComponent.positionX - transformComponent.positionY) * 0.5f;
                        pos.y += (transformComponent.positionX + transformComponent.positionY) * 0.5f * 0.5f;

                        DrawTextureEx(texturePtr->GetTexture(), pos, 0.f, 1.f, WHITE);
                    }
                }
            });
    }
}
