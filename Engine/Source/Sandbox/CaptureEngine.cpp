/* -------------------------------------------------------------------------------- *\
|*                                                                                  *|
|*    Copyright (C) 2019-2024 RedGogh All rights reserved.                          *|
|*                                                                                  *|
|*    Licensed under the Apache License, Version 2.0 (the "License");               *|
|*    you may not use this file except in compliance with the License.              *|
|*    You may obtain a copy of the License at                                       *|
|*                                                                                  *|
|*        http://www.apache.org/licenses/LICENSE-2.0                                *|
|*                                                                                  *|
|*    Unless required by applicable law or agreed to in writing, software           *|
|*    distributed under the License is distributed on an "AS IS" BASIS,             *|
|*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.      *|
|*    See the License for the specific language governing permissions and           *|
|*    limitations under the License.                                                *|
|*                                                                                  *|
\* -------------------------------------------------------------------------------- */
#include "Window/Window.h"
// std
#include <memory>

int main(int argc, char **argv)
{
        std::unique_ptr<Window> window = std::make_unique<Window>("CaptureEngine v1.0", 800, 600);

        window->SetSizeCallback([](Window *HWIN, int w, int h) {
                printf("Window size callback: %d, %d\n", w, h);
                fflush(stdout);
        });

        while (!window->ShouldClose()) {
                window->PollEvents();
        }

        return 0;
}