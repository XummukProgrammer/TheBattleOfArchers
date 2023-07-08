#ifndef _ENGINE_SYSTEM_HEADER_
#define _ENGINE_SYSTEM_HEADER_

namespace Engine
{
	struct Context;

	enum class SystemType
	{
		Update,
		Draw
	};

	enum class SystemPriority
	{
		VeryHigh,
		High,
		Normal,
		Low,
		VeryLow
	};

	class System
	{
	public:
		System() = default;
		virtual ~System() = default;

	public:
		virtual void OnRun(Context* context) = 0;

		virtual SystemType GetType() const = 0;
		virtual SystemPriority GetPriority() const = 0;
	};
}

#endif // _ENGINE_SYSTEM_HEADER_
