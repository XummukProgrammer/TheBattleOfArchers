#include "ResourceTexture.hpp"

namespace Engine
{
    void ResourceTexture::OnLoad(const pugi::xml_node& node, std::string_view path)
    {
        _texture = LoadTexture(path.data());
    }

    void ResourceTexture::OnUnload()
    {
        if (!IsEmpty())
        {
            UnloadTexture(_texture.value());
            _texture.reset();
        }
    }

    bool ResourceTexture::IsEmpty() const
    {
        return !_texture.has_value();
    }
}
