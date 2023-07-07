#ifndef _ENGINE_INPUT_HEADER_
#define _ENGINE_INPUT_HEADER_

#include <functional>
#include <map>

namespace Engine
{
	enum class InputStatus
	{
		Up,
		Pressed,
		Down,
		Released
	};

	class Input final
	{
	public:
		using DefaultCallback = std::function<void(int)>;
		using MouseWheelMoveCallback = std::function<void(float)>;

	public:
		Input() = default;
		~Input() = default;

	public:
		void Init();
		
		void SetOnKeyPressedCallback(const DefaultCallback& callback) { _onKeyPressedCallback = callback; }
		void SetOnKeyDownCallback(const DefaultCallback& callback) { _onKeyDownCallback = callback; }
		void SetOnKeyReleasedCallback(const DefaultCallback& callback) { _onKeyReleasedCallback = callback; }
		void SetOnMouseWheelMoveCallback(const MouseWheelMoveCallback& callback) { _onMouseWheelMoveCallback = callback; }

		void CheckEvents();

	private:
		void CheckKeyboardStatuses();
		void CheckMouseWheelMove();

	private:
		DefaultCallback _onKeyPressedCallback;
		DefaultCallback _onKeyDownCallback;
		DefaultCallback _onKeyReleasedCallback;
		MouseWheelMoveCallback _onMouseWheelMoveCallback;
		std::map<int, InputStatus> _keysStatuses;
	};
}

#endif // _ENGINE_INPUT_HEADER_
