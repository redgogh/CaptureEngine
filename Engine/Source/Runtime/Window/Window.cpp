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
#include "Window.h"

static int GLFW_WINDOW_COUNT = 0;

Window::Window(const char *title, int w, int h)
{
        if (!glfwInit())
                throw std::runtime_error("[GLFW/INIT]: GLFW init failed!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        if ((hwindow = glfwCreateWindow(w, h, title, NULL, NULL)) == NULL)
                throw std::runtime_error("[GLFW/CREATE_WINDOW]: GLFW create window failed!");

        GLFW_WINDOW_COUNT++;
}

Window::~Window()
{
        glfwDestroyWindow(hwindow);
        GLFW_WINDOW_COUNT--;

        if (GLFW_WINDOW_COUNT == 0)
                glfwTerminate();
}

bool Window::ShouldClose()
{
        return glfwWindowShouldClose(hwindow);
}

void Window::PollEvents()
{
        glfwPollEvents();
}