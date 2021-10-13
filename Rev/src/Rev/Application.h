#pragma once

#include "Core.h"
#include "Window.h"
#include "Rev/Events/Event.h"
#include "Rev/Events/ApplicationEvent.h"
#include "Rev/LayerStack.h"

namespace Rev {

	class REV_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// to be defined by client
	Application* CreateApplication();
}


