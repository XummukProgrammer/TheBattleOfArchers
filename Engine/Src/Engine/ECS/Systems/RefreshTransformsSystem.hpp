#ifndef _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_
#define _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_

#include <Engine/ECS/System.hpp>

namespace Engine
{
	class RefreshTransformsSystem final : public System
	{
	public:
		RefreshTransformsSystem() = default;
		~RefreshTransformsSystem() = default;

	public:
		virtual void OnRun(Context* context) override;

		virtual SystemType GetType() const override { return SystemType::Update; }
		virtual SystemPriority GetPriority() const override { return SystemPriority::Low; }
	};
}

#endif // _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_
