#pragma once

#ifdef REV_PLATFORM_WINDOWS

extern Rev::Application* Rev::CreateApplication();

int main(int argc, char** argv)
{
	Rev::Log::Init();
	REV_CORE_TRACE("Entry Point was called");
	auto app = Rev::CreateApplication();
	app->Run();
	delete app;
}

#endif