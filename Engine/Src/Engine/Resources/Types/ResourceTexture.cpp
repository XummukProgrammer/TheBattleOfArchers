#include "ResourceTexture.hpp"

namespace Engine
{
    void ResourceTexture::OnLoad(const pugi::xml_node& node)
    {
        const std::string path = node.attribute("Path").as_string();
        _texture = LoadTexture(path.c_str());
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
