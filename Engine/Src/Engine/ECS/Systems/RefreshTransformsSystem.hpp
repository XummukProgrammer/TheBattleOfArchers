#ifndef _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_
#define _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_

#include <Engine/Core/Context.hpp>

namespace Engine
{
	class RefreshTransformsSystem final
	{
	public:
		static void Run(Context& context);
	};
}

#endif // _ENGINE_REFRESH_TRANSFORMS_SYSTEM_HEADER_
