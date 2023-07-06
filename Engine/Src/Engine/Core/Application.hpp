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
		virtual void OnInit(Application* application) {}
		virtual void OnDeinit(Application* application) {}
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

	private:
		std::unique_ptr<ApplicationDelegate> _delegate;
		Context _context;
	};
}

#endif // _ENGINE_APPLICATION_HEADER_
