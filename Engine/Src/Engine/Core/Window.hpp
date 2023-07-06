#ifndef _ENGINE_WINDOW_HEADER_
#define _ENGINE_WINDOW_HEADER_

#include <string>
#include <functional>

namespace Engine
{
	class Window final
	{
	public:
		using DefaultCallback = std::function<void()>;

	public:
		Window() = default;
		~Window() = default;

	public:
		void Create(unsigned width, unsigned height, std::string_view title);
		bool IsCreated() const;

		void Remove();

		void SetOnUpdateCallback(const DefaultCallback& callback) { _onUpdateCallback = callback; }
		void SetOnDrawCallback(const DefaultCallback& callback) { _onDrawCallback = callback; }

		void Execute();

	private:
		void OnUpdate();
		void OnDraw();

	private:
		bool _isCreated = false;
		DefaultCallback _onUpdateCallback;
		DefaultCallback _onDrawCallback;
	};
}

#endif // _ENGINE_WINDOW_HEADER_
