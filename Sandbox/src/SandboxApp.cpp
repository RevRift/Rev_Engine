#include <Rev.h>

class Sandbox : public Rev::Application
{
public:
	Sandbox()
	{}
	~Sandbox()
	{}
};

Rev::Application* Rev::CreateApplication()
{
	return new Sandbox();
}