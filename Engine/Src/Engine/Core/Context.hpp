#ifndef _ENGINE_CONTEXT_HEADER_
#define _ENGINE_CONTEXT_HEADER_

#include <Engine/Resources/Resources.hpp>
#include <Engine/Core/Window.hpp>
#include <Engine/Scene/Scene.hpp>

namespace Engine
{
	struct Context
	{
		Resources resources;
		Window window;
		Scene scene;
	};
}

#endif // _ENGINE_CONTEXT_HEADER_
