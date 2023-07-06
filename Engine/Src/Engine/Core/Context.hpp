#ifndef _ENGINE_CONTEXT_HEADER_
#define _ENGINE_CONTEXT_HEADER_

#include <Engine/Resources/Resources.hpp>
#include <Engine/Core/Window.hpp>

#include <entt/entt.hpp>

namespace Engine
{
	struct Context
	{
		Resources resources;
		Window window;
		entt::registry registry;
	};
}

#endif // _ENGINE_CONTEXT_HEADER_
