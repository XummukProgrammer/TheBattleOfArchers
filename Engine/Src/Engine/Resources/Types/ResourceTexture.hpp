#ifndef _ENGINE_RESOURCE_TEXTURE_HEADER_
#define _ENGINE_RESOURCE_TEXTURE_HEADER_

#include <Engine/Resources/IResource.hpp>

#include "raylib.h"

namespace Engine
{
	class ResourceTexture final : public IResource
	{
	public:
		ResourceTexture() = default;
		~ResourceTexture() = default;

	public:
		void OnLoad(const pugi::xml_node& node, std::string_view path) override;
		void OnUnload() override;

		bool IsEmpty() const override;

	public:
		const Texture2D& GetTexture() const { return _texture; }

	private:
		Texture2D _texture;
		bool _isEmpty = true;
	};
}

#endif // _ENGINE_RESOURCE_TEXTURE_HEADER_
