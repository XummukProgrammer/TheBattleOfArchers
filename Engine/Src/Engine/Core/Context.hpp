#ifndef _ENGINE_CONTEXT_HEADER_
#define _ENGINE_CONTEXT_HEADER_

#include <Engine/Resources/Resources.hpp>
#include <Engine/Core/Window.hpp>
#include <Engine/Scene/Scene.hpp>
#include <Engine/Core/FileSystem.hpp>
#include <Engine/Settings/Settings.hpp>
#include <Engine/Core/Camera.hpp>
#include <Engine/Core/Input.hpp>
#include <Engine/Core/Time.hpp>

namespace Engine
{
	struct Context
	{
		Resources resources;
		FileSystem fileSystem;
		Window window;
		Scene scene;
		Settings settings;
		Camera camera;
		Input input;
		Time time;
	};
}

#endif // _ENGINE_CONTEXT_HEADER_
