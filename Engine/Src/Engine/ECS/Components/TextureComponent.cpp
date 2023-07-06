#include "TextureComponent.hpp"

namespace Engine
{
    TextureComponent::TextureComponent(std::string_view id, Context& context)
    {
        SetTextureByResources(id, context.resources);
    }

    void TextureComponent::SetTextureByResources(std::string_view id, Resources& resources)
    {
        _weakTexturePtr = resources.GetResource<ResourceTexture>(id);
    }
}
