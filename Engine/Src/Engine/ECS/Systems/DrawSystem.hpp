#ifndef _ENGINE_DRAW_SYSTEM_HEADER_
#define _ENGINE_DRAW_SYSTEM_HEADER_

#include <Engine/Core/Context.hpp>

namespace Engine
{
	class DrawSystem final
	{
	public:
		//DrawSystem() = default;
		//~DrawSystem() = default;

	public:
		static void Run(Context& context);
	};
}

#endif // _ENGINE_DRAW_SYSTEM_HEADER_
