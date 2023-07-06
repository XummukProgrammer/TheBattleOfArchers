#ifndef _ENGINE_RESOURCES_HEADER_
#define _ENGINE_RESOURCES_HEADER_

#include <Engine/Resources/IResource.hpp>

#include <map>
#include <string>
#include <memory>

namespace Engine
{
	class Resources final
	{
	public:
		Resources() = default;
		~Resources() = default;

	public:
		void AddResource(std::string_view id, std::shared_ptr<IResource>&& resource);

		template<typename T>
		std::shared_ptr<T> GetResource(std::string_view id) const;

	private:
		std::map<std::string, std::shared_ptr<IResource>> _resources;
	};

	template<typename T>
	std::shared_ptr<T> Resources::GetResource(std::string_view id) const
	{
		auto it = _resources.find(std::string{ id });
		if (it != _resources.end())
		{
			return std::dynamic_pointer_cast<T>(it->second);
		}
		return nullptr;
	}
}

#endif // _ENGINE_RESOURCES_HEADER_
