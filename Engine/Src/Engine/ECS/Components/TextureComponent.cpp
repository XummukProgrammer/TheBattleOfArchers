#include "TextureComponent.hpp"

namespace Engine
{
    TextureComponent::TextureComponent(std::string_view id, Resources& resources)
    {
        SetTextureByResources(id, resources);
    }

    void TextureComponent::SetTextureByResources(std::string_view id, Resources& resources)
    {
        _weakTexturePtr = resources.GetResource<ResourceTexture>(id);
    }
}
