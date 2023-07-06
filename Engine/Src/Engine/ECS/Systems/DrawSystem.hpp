#ifndef _ENGINE_DRAW_SYSTEM_HEADER_
#define _ENGINE_DRAW_SYSTEM_HEADER_

#include <entt/entt.hpp>

namespace Engine
{
	class DrawSystem final
	{
	public:
		//DrawSystem() = default;
		//~DrawSystem() = default;

	public:
		static void Run(entt::registry& registry);
	};
}

#endif // _ENGINE_DRAW_SYSTEM_HEADER_
