#ifndef _ENGINE_CONTEXT_HEADER_
#define _ENGINE_CONTEXT_HEADER_

#include <Engine/Resources/Resources.hpp>
#include <Engine/Core/Window.hpp>
#include <Engine/Scene/Scene.hpp>
#include <Engine/Core/FileSystem.hpp>
#include <Engine/Settings/Settings.hpp>

namespace Engine
{
	struct Context
	{
		Resources resources;
		FileSystem fileSystem;
		Window window;
		Scene scene;
		Settings settings;
	};
}

#endif // _ENGINE_CONTEXT_HEADER_
