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


#ifndef MUSICPLAYERLAYER_H
#define MUSICPLAYERLAYER_H

#include <string_view>
#include <array>

#include <Assets/AudioClip.hh>
#include <Audio/AudioDevice.hh>
#include <Core/LayerStack.hh>

namespace Mikoto {
    class MusicPlayerLayer final : public ILayer {
    public:
        explicit MusicPlayerLayer( std::string_view name );

        auto OnCreate() -> void override;
        auto OnDestroy() -> void override;
        auto OnUpdate( float deltaTime ) -> void override;

        auto OnEvent(Event &event) -> void override;

    private:
        auto LoadAudio( std::string_view path ) -> void;
        auto DrawLoadAudioUI() -> void;

    private:
        std::vector<AudioHandle> m_Tracks{};

        AudioSourceHandle m_Target{};
        AudioSourceHandle m_NewAudio{ };

        int m_SelectedIndex{ -1 };
        float m_Volume{ 0.5f };

        std::array<char, 512> m_InputPath{};
    };
}// namespace Mikoto

#endif //MUSICPLAYERLAYER_H
