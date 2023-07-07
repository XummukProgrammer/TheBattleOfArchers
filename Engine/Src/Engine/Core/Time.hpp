#ifndef _ENGINE_TIME_HEADER_
#define _ENGINE_TIME_HEADER_

namespace Engine
{
	class Time final
	{
	public:
		Time() = default;
		~Time() = default;

	public:
		float GetDeltaTime() const;
	};
}

#endif // _ENGINE_TIME_HEADER_
