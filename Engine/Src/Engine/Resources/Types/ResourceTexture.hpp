#ifndef _ENGINE_RESOURCE_TEXTURE_HEADER_
#define _ENGINE_RESOURCE_TEXTURE_HEADER_

#include <Engine/Resources/IResource.hpp>

#include "raylib.h"

#include <optional>

namespace Engine
{
	class ResourceTexture final : public IResource
	{
	public:
		ResourceTexture() = default;
		~ResourceTexture() = default;

	public:
		void OnLoad(const pugi::xml_node& node) override;
		void OnUnload() override;

		bool IsEmpty() const override;

	public:
		std::optional<Texture2D>& GetTexture() { return _texture; }
		const std::optional<Texture2D>& GetTexture() const { return _texture; }

	private:
		std::optional<Texture2D> _texture;
	};
}

#endif // _ENGINE_RESOURCE_TEXTURE_HEADER_
