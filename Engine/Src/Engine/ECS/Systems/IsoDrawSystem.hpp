#ifndef _ENGINE_ISO_DRAW_SYSTEM_HEADER_
#define _ENGINE_ISO_DRAW_SYSTEM_HEADER_

#include <Engine/ECS/System.hpp>

namespace Engine
{
	class IsoDrawSystem final : public System
	{
	public:
		IsoDrawSystem() = default;
		~IsoDrawSystem() = default;

	public:
		void OnRun(Context* context) override;

		SystemType GetType() const override { return SystemType::Draw; }
		SystemPriority GetPriority() const override { return SystemPriority::VeryLow; }
	};
}

#endif // _ENGINE_ISO_DRAW_SYSTEM_HEADER_
