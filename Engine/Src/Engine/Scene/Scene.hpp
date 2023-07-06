#ifndef _ENGINE_SCENE_HEADER_
#define _ENGINE_SCENE_HEADER_

#include <entt/entt.hpp>

namespace Engine
{
	class Scene final
	{
	public:
		Scene() = default;
		~Scene() = default;

	public:
		entt::registry& GetRegistry() { return _registry; }
		const entt::registry& GetRegistry() const { return _registry; }

	private:
		entt::registry _registry;
	};
}

#endif // _ENGINE_SCENE_HEADER_
