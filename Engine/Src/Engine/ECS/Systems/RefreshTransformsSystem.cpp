#include "RefreshTransformsSystem.hpp"

#include <Engine/Core/Context.hpp>

#include <Engine/ECS/Components/RefreshTransformsComponent.hpp>
#include <Engine/ECS/Components/TransformComponent.hpp>

namespace Engine
{
    void RefreshTransformsSystem::OnRun(Context* context)
    {
        auto& registry = context->scene.GetRegistry();

        auto view = registry.view<const RefreshTransformsComponent>();
        view.each([&registry, context](entt::entity entity, const RefreshTransformsComponent&)
            {
                registry.sort<TransformComponent>([](const TransformComponent& left, const TransformComponent& right)
                    {
                        return left.order < right.order;
                    });

                registry.destroy(entity);
                context->scene.OnTransformsRefreshed();
            });
    }
}
