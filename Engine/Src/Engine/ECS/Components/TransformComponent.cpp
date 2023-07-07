#include "TransformComponent.hpp"

namespace Engine
{
    TransformComponent::TransformComponent(const Vector2& position, const Vector2& offset, int order)
        : position(position)
        , offset(offset)
        , order(order)
    {
    }
}
