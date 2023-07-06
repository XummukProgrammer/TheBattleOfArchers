#ifndef _ENGINE_RESOURCES_PARSER_HEADER_
#define _ENGINE_RESOURCES_PARSER_HEADER_

#include <Engine/Core/Context.hpp>

namespace Engine
{
	class ResourcesParser final
	{
	public:
		ResourcesParser() = default;
		~ResourcesParser() = default;

	public:
		static void LoadFromXMLFile(std::string_view filePath, Context& context);
	};
}

#endif // _ENGINE_RESOURCES_PARSER_HEADER_
