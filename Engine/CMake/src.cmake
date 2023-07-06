
set(ENGINE_HEADERS
	src/Engine/Engine.hpp
	
	src/Engine/Resources/IResource.hpp
	src/Engine/Resources/Resources.hpp
	src/Engine/Resources/ResourcesParser.hpp
	src/Engine/Resources/Types/ResourceTexture.hpp
	
	src/Engine/ECS/Components/TextureComponent.hpp
	
	src/Engine/ECS/Systems/DrawSystem.hpp
)

set(ENGINE_SOURCES
	src/Engine/Engine.cpp
	
	src/Engine/Resources/Resources.cpp
	src/Engine/Resources/ResourcesParser.cpp
	src/Engine/Resources/Types/ResourceTexture.cpp
	
	src/Engine/ECS/Components/TextureComponent.cpp
	
	src/Engine/ECS/Systems/DrawSystem.cpp
)
