#include "flpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace FarLight
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer"), _time(0.0) { }

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasMouseCursors;

		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::GetInstance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		double time = glfwGetTime();
		io.DeltaTime = _time > 0.0 ? (time - _time) : (1.0 / 60);
		_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
	}
}
