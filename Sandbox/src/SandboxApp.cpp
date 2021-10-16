#include <Rev.h>

class ExampleLayer : public Rev::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
	}

	void OnEvent(Rev::Event& event) override
	{
		REV_INFO("{0}", event);
	}
};

class Sandbox : public Rev::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer);
		PushOverlay(new Rev::ImGuiLayer());
	}
	~Sandbox()
	{}
};

Rev::Application* Rev::CreateApplication()
{
	return new Sandbox();
}