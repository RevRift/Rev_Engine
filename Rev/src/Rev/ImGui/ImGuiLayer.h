#pragma once
#include "revpch.h"

#include "Rev/Events/MouseEvent.h"
#include "Rev/Events/KeyEvent.h"
#include "Rev/Events/ApplicationEvent.h"
#include "Rev/Layer.h"

namespace Rev {

	class REV_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool OnAppTickEvent(AppTickEvent& e);
		bool OnAppUpdateEvent(AppUpdateEvent& e);
		bool OnAppRenderEvent(AppRenderEvent& e);
	private:
		float m_Time = 0.0f;
	};

}