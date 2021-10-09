#pragma once

#include "Core.h"
#include "Window.h"
#include "Rev/Events/Event.h"
#include "Rev/Events/ApplicationEvent.h"

namespace Rev {

	class REV_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be defined by client
	Application* CreateApplication();
}


