#pragma once

// For use by FarLight applications

//---Core-----------------------------
#include "FarLight/Core/Core.h"
//------------------------------------
//---Abstraction----------------------
#include "FarLight/Abstraction/Singleton/Singleton.h"
//------------------------------------
//---Basic-Functionality--------------
#include "FarLight/BasicFunctionality/Application.h"
#include "FarLight/BasicFunctionality/Timer/Timestep.h"

#include "FarLight/BasicFunctionality/Camera/Camera.h"
#include "FarLight/BasicFunctionality/Camera/RenderOrthoCamera.h"
#include "FarLight/BasicFunctionality/Camera/OrthographicCameraController.h"
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
#include "FarLight/InputSystem/InputManager.h"
#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"
//------------------------------------
//---Entity-Component-System----------
#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"
#include "FarLight/EntityComponentSystem/Components/Script/NativeScriptComponent.h"

#include "FarLight/EntityComponentSystem/ScriptableBehaviour.h"

#include "FarLight/EntityComponentSystem/Entity.h"
#include "FarLight/EntityComponentSystem/Scene.h"
//------------------------------------
//---Virtual-File-System--------------
#include "FarLight/VirtualFileSystem/FileSystem.h"
//------------------------------------
//---Render-System--------------------
#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

//#include "FarLight/RenderSystem/Camera/OrthographicCameraController.h"

#include "FarLight/RenderSystem/Shader/Shader.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"
#include "FarLight/RenderSystem/Texture/TextureAtlas/AtlasMap.h"

#include "FarLight/RenderSystem/Framebuffer/Framebuffer.h"
#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"
#include "FarLight/RenderSystem/VertexArray/VertexArray.h"
//------------------------------------
//---Profiling------------------------
#include "FarLight/Profiling/Instrumentor.h"
#include "FarLight/Profiling/InstrumentationTimer.h"
//------------------------------------
