#ifndef _ENGINE_ISO_DRAW_SYSTEM_HEADER_
#define _ENGINE_ISO_DRAW_SYSTEM_HEADER_

#include <Engine/Core/Context.hpp>

namespace Engine
{
	class IsoDrawSystem final
	{
	public:
		//IsoDrawSystem() = default;
		//~IsoDrawSystem() = default;

	public:
		static void Run(Context& context);
	};
}

#endif // _ENGINE_ISO_DRAW_SYSTEM_HEADER_
