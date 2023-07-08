#ifndef _GAME_SPAWN_ARCHES_SYSTEM_HEADER_
#define _GAME_SPAWN_ARCHES_SYSTEM_HEADER_

#include <Engine/ECS/System.hpp>

namespace Game
{
	class SpawnArchersSystem final : public Engine::System
	{
	public:
		void OnRun(Engine::Context* context) override;

		Engine::SystemType GetType() const override { return Engine::SystemType::Update; }
		Engine::SystemPriority GetPriority() const override { return Engine::SystemPriority::VeryHigh; }
	};
}

#endif // _GAME_SPAWN_ARCHES_SYSTEM_HEADER_
