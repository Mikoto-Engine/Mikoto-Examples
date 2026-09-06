//    Copyright 2026 ケイト
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef GRAPHICSLAYER_HH
#define GRAPHICSLAYER_HH

#include <string_view>

#include <Renderer/Core/SceneRenderer.hh>
#include <Assets/Model.hh>
#include <Core/LayerStack.hh>
#include <Platform/Window.hh>
#include <Scene/Scene.hh>
#include <Scene/SceneCamera.hh>

namespace Mikoto {

    class GraphicsLayer final : public ILayer {
    public:
        explicit GraphicsLayer( std::string_view name, const Window* window );

        auto OnCreate() -> void override;
        auto OnDestroy() -> void override;
        auto OnUpdate( float deltaTime ) -> void override;

        auto OnEvent(Event &event) -> void override;

    private:
        auto LoadModels() -> void;
        auto SetupScene() -> void;
        auto SetupCamera() -> void;
        auto SetupRenderer() -> void;

        auto UpdateListener() -> void;

        auto UpdateCamera( float timeStep ) -> void;
        auto DrawViewport() const -> void;
        auto DisplayCameraDebugInfo() const -> void;

    private:
        Entity* m_Listener{ nullptr };

        Scene* m_MainScene{};
        Unique<SceneCamera> m_SceneCamera{};
        Unique<SceneRenderer> m_Renderer{};

        const Window* m_Window{};

        ModelHandle m_ModelSingleMesh{};
        ModelHandle m_ModelMultipleMeshes{};
    };
}



#endif //GRAPHICSLAYER_HH
