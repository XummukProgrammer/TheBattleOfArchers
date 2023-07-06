#include "Resources.hpp"

namespace Engine
{
    void Resources::AddResource(std::string_view id, std::shared_ptr<IResource>&& resource)
    {
        _resources[std::string{ id }] = std::move(resource);
    }
}
