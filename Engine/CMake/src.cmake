
set(ENGINE_HEADERS
	src/Engine/Engine.hpp
	
	src/Engine/Core/Application.hpp
	src/Engine/Core/Context.hpp
	src/Engine/Core/Window.hpp
	src/Engine/Core/FileSystem.hpp
	
	src/Engine/Resources/IResource.hpp
	src/Engine/Resources/Resources.hpp
	src/Engine/Resources/ResourcesParser.hpp
	src/Engine/Resources/Types/ResourceTexture.hpp
	
	src/Engine/Scene/Scene.hpp
	
	src/Engine/ECS/Components/TextureComponent.hpp
	
	src/Engine/ECS/Systems/DrawSystem.hpp
)

set(ENGINE_SOURCES
	src/Engine/Engine.cpp
	
	src/Engine/Core/Application.cpp
	src/Engine/Core/Context.cpp
	src/Engine/Core/Window.cpp
	src/Engine/Core/FileSystem.cpp
	
	src/Engine/Resources/Resources.cpp
	src/Engine/Resources/ResourcesParser.cpp
	src/Engine/Resources/Types/ResourceTexture.cpp
	
	src/Engine/Scene/Scene.cpp
	
	src/Engine/ECS/Components/TextureComponent.cpp
	
	src/Engine/ECS/Systems/DrawSystem.cpp
)
