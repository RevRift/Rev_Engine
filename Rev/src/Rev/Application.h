#pragma once
#include "revpch.h"

#include "Rev/Window.h"
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

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	// to be defined by client
	Application* CreateApplication();
}


