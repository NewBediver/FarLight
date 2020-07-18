#pragma once

// For use by FarLight applications
#include "FarLight/Application.h"

#include "FarLight/Core/Timestep.h"

//---Logger---------------------------
#include "FarLight/Logger.h"
//------------------------------------
//---Layer-System---------------------
#include "FarLight/LayerSystem/Layer.h"
#include "FarLight/LayerSystem/EngineLayers/ImGuiLayer.h"
//------------------------------------
//---Input-System---------------------
#include "FarLight/InputSystem/Input.h"
#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"
//------------------------------------
//---Render-System--------------------
#include "FarLight/RenderSystem/Renderer.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"
#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
//------------------------------------
//---Entry-Point----------------------
//#include "FarLight/EntryPoint.h"
//------------------------------------