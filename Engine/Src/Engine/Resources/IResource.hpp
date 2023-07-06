#ifndef _ENGINE_INTERFACE_RESOURCE_HEADER_
#define _ENGINE_INTERFACE_RESOURCE_HEADER_

#include <pugixml.hpp>

#include <string>

namespace Engine
{
	class IResource
	{
	public:
		IResource() = default;
		virtual ~IResource() = default;

	public:
		virtual void OnLoad(const pugi::xml_node& node, std::string_view path) = 0;
		virtual void OnUnload() = 0;

		virtual bool IsEmpty() const = 0;
	};
}

#endif // _ENGINE_INTERFACE_RESOURCE_HEADER_
