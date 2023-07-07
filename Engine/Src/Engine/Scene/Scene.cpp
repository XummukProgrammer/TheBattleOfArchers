#include "Scene.hpp"

#include <Engine/ECS/Components/RefreshTransformsComponent.hpp>

namespace Engine
{
    void Scene::RefreshTransforms()
    {
        if (!_isTransformsRefreshed)
        {
            return;
        }

        entt::entity entity = _registry.create();
        _registry.emplace<RefreshTransformsComponent>(entity);

        _isTransformsRefreshed = false;
    }

    void Scene::OnTransformsRefreshed()
    {
        _isTransformsRefreshed = true;
    }
}
