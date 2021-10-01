#pragma once

#ifdef REV_PLATFORM_WINDOWS

extern Rev::Application* Rev::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rev::CreateApplication();
	app->Run();
	delete app;
}

#endif