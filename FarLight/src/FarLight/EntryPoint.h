#pragma once

#ifdef FL_PLATFORM_WINDOWS

extern FarLight::Application* FarLight::CreateApplication();

int main(int args, char** argv)
{
	printf("FarLight Engine!\n");
	auto app = FarLight::CreateApplication();
	app->Run();
	delete app;
}

#endif