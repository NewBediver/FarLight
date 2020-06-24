#include <FarLight.h>

class Sandbox : public FarLight::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

FarLight::Application* FarLight::CreateApplication()
{
	return new Sandbox();
}