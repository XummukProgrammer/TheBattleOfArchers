#ifndef _ENGINE_APPLICATION_HEADER_
#define _ENGINE_APPLICATION_HEADER_

#include <Engine/Core/Context.hpp>

#include <memory>

namespace Engine
{
	class Application;

	class ApplicationDelegate
	{
	public:
		ApplicationDelegate() = default;
		virtual ~ApplicationDelegate() = default;

	public:
		virtual void OnInit(Application* app) {}
		virtual void OnDeinit(Application* app) {}

		virtual void OnKeyPressed(Application* app, int key) {}
		virtual void OnKeyDown(Application* app, int key) {}
		virtual void OnKeyReleased(Application* app, int key) {}

		virtual void OnMouseWheelMove(Application* app, float value) {}
	};

	class Application final
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		void Execute(char** argv);

	public:
		void SetDelegate(std::unique_ptr<ApplicationDelegate>&& delegate) { _delegate = std::move(delegate); }

		Context& GetContext() { return _context; }
		const Context& GetContext() const { return _context; }

	private:
		void OnInit();
		void OnDeinit();

		void OnUpdate();
		void OnDraw();

		void OnKeyPressed(int key);
		void OnKeyDown(int key);
		void OnKeyReleased(int key);

		void OnMouseWheelMove(float value);

	private:
		std::unique_ptr<ApplicationDelegate> _delegate;
		Context _context;
	};
}

#endif // _ENGINE_APPLICATION_HEADER_
