#include "revpch.h"

#include "Application.h"
#include "Rev/Events/ApplicationEvent.h"
#include "Rev/Log.h"

namespace Rev {

	Application::Application()
	{}
	Application::~Application()
	{}
	void Application::Run()
	{
		REV_CORE_TRACE("Welcome to Rev Engine!");
		WindowResizeEvent e(7200, 800);
		REV_CORE_INFO(e);
	}

}