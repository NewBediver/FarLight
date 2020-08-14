#pragma once

// For use by FarLight applications

//---Core-----------------------------
#include "FarLight/Core/Core.h"
#include "FarLight/Core/Application.h"
#include "FarLight/Core/Timestep.h"
//------------------------------------
//---Log-System-----------------------
#include "FarLight/LogSystem/Logger.h"
//------------------------------------
//---Event-System---------------------
#include "FarLight/EventSystem/Event.h"
#include "FarLight/EventSystem/EventDispatcher.h"
//------------------------------------
//---Layer-System---------------------
#include "FarLight/LayerSystem/Layer.h"
//------------------------------------
//---Input-System---------------------
#include "FarLight/InputSystem/Input.h"
#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"
//------------------------------------
//---Render-System--------------------
#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"
#include "FarLight/RenderSystem/Camera/OrthographicCameraController.h"
#include "FarLight/RenderSystem/Shader/Shader.h"
#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Texture/SubTexture.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"
#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
//------------------------------------
//---Profiling------------------------
#include "FarLight/Profiling/Instrumentor.h"
#include "FarLight/Profiling/InstrumentationTimer.h"
//------------------------------------