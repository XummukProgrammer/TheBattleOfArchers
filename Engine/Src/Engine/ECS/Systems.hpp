#ifndef _ENGINE_SYSTEMS_HEADER_
#define _ENGINE_SYSTEMS_HEADER_

#include <Engine/ECS/System.hpp>

#include <map>
#include <list>
#include <memory>

namespace Engine
{
	struct Context;

	class Systems final
	{
	public:
		Systems() = default;
		~Systems() = default;

	public:
		void OnUpdate(Context* context);
		void OnDraw(Context* context);

		template<typename T>
		void AddAndCreateSystem();

	private:
		void RunSystems(Context* context, SystemType type);

	private:
		std::map<SystemType, std::map<SystemPriority, std::list<std::unique_ptr<System>>>> _data;
	};

	template<typename T>
	void Systems::AddAndCreateSystem()
	{
		auto newSystem = std::make_unique<T>();
		_data[newSystem->GetType()][newSystem->GetPriority()].push_back(std::move(newSystem));
	}
}

#endif // _ENGINE_SYSTEMS_HEADER_
