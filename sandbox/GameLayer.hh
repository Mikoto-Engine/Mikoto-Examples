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

#ifndef GAMELAYER_HH
#define GAMELAYER_HH

#include <string_view>

#include <imgui.h>

#include <Assets/AudioClip.hh>
#include <Core/LayerStack.hh>


namespace Mikoto {
    class GameLayer final : public ILayer {
    public:
        explicit GameLayer( std::string_view name );

        auto OnUpdate( float deltaTime ) -> void override;
        auto OnCreate() -> void override;
        auto OnDestroy() -> void override;

        auto OnEvent(Event &event) -> void override;

    private:
        bool m_ShowDemo{ false };
        bool m_ShowAnotherWindow{ false };
        Vec4F m_ClearColor{ 0.45f, 0.55f, 0.60f, 1.00f };
    };
}// namespace Mikoto


#endif//GAMELAYER_HH
