#ifndef _ENGINE_RESOURCES_PARSER_HEADER_
#define _ENGINE_RESOURCES_PARSER_HEADER_

#include <Engine/Resources/Resources.hpp>

namespace Engine
{
	class ResourcesParser final
	{
	public:
		ResourcesParser() = default;
		~ResourcesParser() = default;

	public:
		static void LoadFromXMLFile(std::string_view filePath, Resources& resources);
	};
}

#endif // _ENGINE_RESOURCES_PARSER_HEADER_
