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
#pragma once

#include <GLFW/glfw3.h>
// std
#include <stdexcept>

class Window;

typedef void (*PFN_WindowSizeCallback) (Window *window, int w, int h);

inline static void poll_events()
{
        glfwPollEvents();
}

class Window {
public:
        Window(int w, int h, const char *title);
       ~Window();

        bool should_close();

        void set_size(int w, int h);
        void set_size_callback(PFN_WindowSizeCallback v_SizeCallback);

        void get_size(int *w, int *h);

private:
        GLFWwindow *HWINDOW = NULL;

        PFN_WindowSizeCallback fn_size_callback = NULL;
};