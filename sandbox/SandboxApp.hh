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


#ifndef MIKOTO_SANDBOX_APP_HH
#define MIKOTO_SANDBOX_APP_HH

#include <Assets/AudioClip.hh>
#include <Audio/AudioDevice.hh>
#include <Common/Application.hh>
#include <Core/EventService.hh>
#include <Library/Utility/Types.hh>
#include <Platform/Window.hh>
#include <Core/LayerStack.hh>

namespace Mikoto {

    class SandboxApp final : public Application, public Subscriber {
    public:

        auto Run() -> void override;

        auto Init() -> void override;
        auto Shutdown() -> void override;

        auto SetWindow(Window* window) -> void;

    private:
        auto Update() -> void override;

    private:
        auto SetupEventCallbacks() -> void;

        Window* m_Window{};
    };
}


#endif//MIKOTO_SANDBOX_APP_HH
