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
		if (event.GetEventType() == Rev::EventType::KeyPressed)
		{
			Rev::KeyPressedEvent& e = (Rev::KeyPressedEvent&)event;
			REV_TRACE("{0}", (char)e.GetKeyCode());
		}
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