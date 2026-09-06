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


// C++ Standard Library
#include <memory>

// Project Headers
#include <SandboxApp.hh>

Mikoto::Window* g_Window{ nullptr };
Mikoto::SandboxApp* g_Application{ nullptr };

auto InitializeWindow() -> void {
    using namespace Mikoto;

    WindowProperties properties{};
    properties.Resizable = true;
    properties.Title = "Sandbox Application [Vulkan]";
    properties.Backend = GraphicsAPI::VULKAN_API;
    properties.Width = 1280;
    properties.Height = 720;

    g_Window = Window::Create( properties );

    g_Window->Init();
}

auto main(int, char**) -> int {
    using namespace Mikoto;

    InitializeWindow();

    g_Application = new SandboxApp{};

    g_Application->SetWindow( g_Window );
    g_Application->Init();

    g_Application->Run();

    g_Application->Shutdown();

    return 0;
}