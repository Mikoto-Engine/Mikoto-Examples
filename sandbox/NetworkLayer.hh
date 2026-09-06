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


#ifndef NETWORK_LAYER_HH
#define NETWORK_LAYER_HH

#include <vector>
#include <string_view>

#include <ankerl/unordered_dense.h>

#include <Assets/AudioClip.hh>
#include <Core/LayerStack.hh>
#include <Networking/Socket.hh>

namespace Mikoto {

    class NetworkLayer final : public ILayer {
    public:
        explicit NetworkLayer( std::string_view name );

        auto OnUpdate( float deltaTime ) -> void override;
        auto OnCreate() -> void override;
        auto OnDestroy() -> void override;

        auto OnEvent(Event &event) -> void override;

    private:
        auto DrawAnimeWindow() -> void;

    private:
        struct AnimeInfo {
            Int32 id{};
            std::string title{};
        };

    private:
        SocketHandle m_LocalHostSocket{};

        bool m_HasFetchedList{ false };
        Int32 m_SelectedAnimeIndex{};

        std::vector<AnimeInfo> m_AnimeList{};
        ankerl::unordered_dense::map<Int32, std::string> m_SelectedAnimeJsons{};


    };
}// namespace Mikoto



#endif //
