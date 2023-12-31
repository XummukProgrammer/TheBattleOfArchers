﻿#include "ResourcesParser.hpp"

#include <Engine/Resources/Types/ResourceTexture.hpp>

#include <pugixml.hpp>

namespace Engine
{
    void ResourcesParser::LoadFromXMLFile(std::string_view filePath, Context& context)
    {
        pugi::xml_document doc;
        auto result = doc.load_file(filePath.data());
        if (!result)
        {
            return;
        }

        for (const auto& node : doc.child("Resources").children("Resource"))
        {
            const std::string type = node.attribute("Type").as_string();
            std::shared_ptr<IResource> resource = nullptr;
            if (type == "Texture")
            {
                resource = std::make_shared<ResourceTexture>();
            }

            if (resource)
            {
                const std::string path = context.fileSystem.BuildPath(DirType::Assets, node.attribute("Path").as_string());
                resource->OnLoad(node, path);
                if (!resource->IsEmpty())
                {
                    const std::string id = node.attribute("Id").as_string();
                    context.resources.AddResource(id, std::move(resource));
                }
            }
        }
    }
}
