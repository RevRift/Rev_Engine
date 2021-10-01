#pragma once

#include "Core.h"

namespace Rev {

	class REV_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// to be defined by client
	Application* CreateApplication();
}


