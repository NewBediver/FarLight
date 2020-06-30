#include "Sandbox.h"

FarLight::Application* FarLight::CreateApplication()
{
	return new Sandbox();
}