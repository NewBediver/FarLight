#include "flpch.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Serializers/Component/ComponentSerializerConfiguration.h"

namespace FarLight
{
    bool ComponentSerializerConfiguration::IsComponentExists(const EngineID& id) const noexcept
    {
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                return true;
            }
        }
        return false;
    }

    void ComponentSerializerConfiguration::EraseComponent(const EngineID& id) noexcept
    {
        if (!IsComponentExists(id)) return;

        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                node = m_PropertyTree.erase(node);
                break;
            }
        }
    }


    boost::property_tree::ptree ComponentSerializerConfiguration::CreateTagComponentTree(Ref<TagComponent> component) const noexcept
    {
        boost::property_tree::ptree tree;
        tree.put<std::string>(m_ComponentNodeName + ".<xmlattr>.id", component->GetId().ToString());
        
        tree.put<std::string>(m_ComponentNodeName + ".Tag", component->GetTag());
        
        return tree;
    }

    Ref<TagComponent> ComponentSerializerConfiguration::CreateTagComponent(const EngineID& id) const noexcept
    {
        Ref<TagComponent> tag = CreateRef<TagComponent>(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                tag->SetTag(node->second.get<std::string>("Tag"));
                break;
            }
        }
        return tag;
    }


    boost::property_tree::ptree ComponentSerializerConfiguration::CreateTransformComponentTree(Ref<TransformComponent> component) const noexcept
    {
        boost::property_tree::ptree tree;
        tree.put<std::string>(m_ComponentNodeName + ".<xmlattr>.id", component->GetId().ToString());
        
        const auto& pos = component->GetPosition();
        tree.put<float>(m_ComponentNodeName + ".Position.X", pos.x);
        tree.put<float>(m_ComponentNodeName + ".Position.Y", pos.y);
        tree.put<float>(m_ComponentNodeName + ".Position.Z", pos.z);

        const auto& size = component->GetSize();
        tree.put<float>(m_ComponentNodeName + ".Size.X", size.x);
        tree.put<float>(m_ComponentNodeName + ".Size.Y", size.y);
        tree.put<float>(m_ComponentNodeName + ".Size.Z", size.z);

        const auto& rot = component->GetRotation();
        tree.put<float>(m_ComponentNodeName + ".Rotation.X", rot.x);
        tree.put<float>(m_ComponentNodeName + ".Rotation.Y", rot.y);
        tree.put<float>(m_ComponentNodeName + ".Rotation.Z", rot.z);
        
        return tree;
    }

    Ref<TransformComponent> ComponentSerializerConfiguration::CreateTransformComponent(const EngineID& id) const noexcept
    {
        Ref<TransformComponent> transform = CreateRef<TransformComponent>(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                transform->SetPosition(glm::vec3(node->second.get<float>("Position.X"),
                                                 node->second.get<float>("Position.Y"),
                                                 node->second.get<float>("Position.Z")));
                transform->SetSize(glm::vec3(node->second.get<float>("Size.X"),
                                             node->second.get<float>("Size.Y"),
                                             node->second.get<float>("Size.Z")));
                transform->SetRotation(glm::vec3(node->second.get<float>("Rotation.X"),
                                                 node->second.get<float>("Rotation.Y"),
                                                 node->second.get<float>("Rotation.Z")));
                break;
            }
        }
        return transform;
    }

    boost::property_tree::ptree ComponentSerializerConfiguration::CreateRenderComponentTree(Ref<RenderComponent> component) const noexcept
    {
        boost::property_tree::ptree tree;
        tree.put<std::string>(m_ComponentNodeName + ".<xmlattr>.id", component->GetId().ToString());
        
        const auto& col = component->GetColor();
        tree.put<float>(m_ComponentNodeName + ".Color.R", col.r);
        tree.put<float>(m_ComponentNodeName + ".Color.G", col.g);
        tree.put<float>(m_ComponentNodeName + ".Color.B", col.b);
        tree.put<float>(m_ComponentNodeName + ".Color.A", col.a);
        
        return tree;
    }

    Ref<RenderComponent> ComponentSerializerConfiguration::CreateRenderComponent(const EngineID& id) const noexcept
    {
        Ref<RenderComponent> render = CreateRef<RenderComponent>(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                render->SetColor(glm::vec4(node->second.get<float>("Color.R"),
                                           node->second.get<float>("Color.G"),
                                           node->second.get<float>("Color.B"),
                                           node->second.get<float>("Color.A")));
                break;
            }
        }
        return render;
    }

    boost::property_tree::ptree ComponentSerializerConfiguration::CreateCameraComponentTree(Ref<CameraComponent> component) const noexcept
    {
        boost::property_tree::ptree tree;
        tree.put<std::string>(m_ComponentNodeName + ".<xmlattr>.id", component->GetId().ToString());
        
        tree.put<bool>(m_ComponentNodeName + ".IsPrimary", component->IsPrimary());
        tree.put<bool>(m_ComponentNodeName + ".IsFixedAspectRatio", component->IsFixedAspectRatio());

        const auto& cam = component->GetCamera();

        tree.put<unsigned>(m_ComponentNodeName + ".Camera.Resolution.Width", cam->GetResolutionWidth());
        tree.put<unsigned>(m_ComponentNodeName + ".Camera.Resolution.Height", cam->GetResolutionHeight());
        tree.put<float>(m_ComponentNodeName + ".Camera.Zoom", cam->GetZoom());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Left", cam->GetLeftBound());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Right", cam->GetRightBound());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Bottom", cam->GetBottomBound());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Top", cam->GetTopBound());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Near", cam->GetNearBound());
        tree.put<float>(m_ComponentNodeName + ".Camera.ViewFrustum.Far", cam->GetFarBound());

        const auto& front = cam->GetFrontDirection();
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Front.X", front.x);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Front.Y", front.y);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Front.Z", front.z);

        const auto& up = cam->GetUpDirection();
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Up.X", up.x);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Up.Y", up.y);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Up.Z", up.z);

        const auto& right = cam->GetRightDirection();
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Right.X", right.x);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Right.Y", right.y);
        tree.put<float>(m_ComponentNodeName + ".Camera.DirectionVectors.Right.Z", right.z);

        const auto& col = cam->GetBackgroundColor();
        tree.put<float>(m_ComponentNodeName + ".Camera.BackgroundColor.R", col.r);
        tree.put<float>(m_ComponentNodeName + ".Camera.BackgroundColor.G", col.g);
        tree.put<float>(m_ComponentNodeName + ".Camera.BackgroundColor.B", col.b);
        tree.put<float>(m_ComponentNodeName + ".Camera.BackgroundColor.A", col.a);
        
        return tree;
    }

    Ref<CameraComponent> ComponentSerializerConfiguration::CreateCameraComponent(const EngineID& id) const noexcept
    {
        Ref<CameraComponent> camera = CreateRef<CameraComponent>(id);
        for (auto& node = m_PropertyTree.begin(); node != m_PropertyTree.end(); ++node)
        {
            if (node->first == m_ComponentNodeName && node->second.get<std::string>("<xmlattr>.id") == id.ToString())
            {
                camera->SetIsPrimary(node->second.get<bool>("IsPrimary"));
                camera->SetIsFixedAspectRatio(node->second.get<bool>("IsFixedAspectRatio"));
                camera->m_Camera->SetResolutionWidth(node->second.get<unsigned>("Camera.Resolution.Width"));
                camera->m_Camera->SetResolutionHeight(node->second.get<unsigned>("Camera.Resolution.Height"));
                camera->m_Camera->SetZoom(node->second.get<float>("Camera.Zoom"));
                camera->m_Camera->SetLeftBound(node->second.get<float>("Camera.ViewFrustum.Left"));
                camera->m_Camera->SetRightBound(node->second.get<float>("Camera.ViewFrustum.Right"));
                camera->m_Camera->SetTopBound(node->second.get<float>("Camera.ViewFrustum.Top"));
                camera->m_Camera->SetBottomBound(node->second.get<float>("Camera.ViewFrustum.Bottom"));
                camera->m_Camera->SetNearBound(node->second.get<float>("Camera.ViewFrustum.Near"));
                camera->m_Camera->SetFarBound(node->second.get<float>("Camera.ViewFrustum.Far"));
                camera->m_Camera->SetBackgroundColor({ node->second.get<float>("Camera.BackgroundColor.R"),
                                                       node->second.get<float>("Camera.BackgroundColor.G"),
                                                       node->second.get<float>("Camera.BackgroundColor.B"),
                                                       node->second.get<float>("Camera.BackgroundColor.A") });
                break;
            }
        }
        return camera;
    }
}
