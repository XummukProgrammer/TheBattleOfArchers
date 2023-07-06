#include "ResourceTexture.hpp"

namespace Engine
{
    void ResourceTexture::OnLoad(const pugi::xml_node& node, std::string_view path)
    {
        _texture = LoadTexture(path.data());
        _isEmpty = false;
    }

    void ResourceTexture::OnUnload()
    {
        if (!IsEmpty())
        {
            UnloadTexture(_texture);
            _isEmpty = true;
        }
    }

    bool ResourceTexture::IsEmpty() const
    {
        return _isEmpty;
    }
}
