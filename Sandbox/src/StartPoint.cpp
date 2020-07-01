#include "Sandbox.h"

#include <FarLight/EntryPoint.h>

FarLight::Application* FarLight::CreateApplication()
{
	return new Sandbox();
}