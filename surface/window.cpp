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
#include "window.h"

static int created_window_count = 0;

Window::Window(int w, int h, const char *title)
{
        if (!glfwInit())
                throw std::runtime_error("[GLFW]: glfw libraries init failed!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        if (!(HWINDOW = glfwCreateWindow(w, h, title, NULL, NULL)))
                throw std::runtime_error("[GLFW]: glfw create window failed!");

        created_window_count++;
        glfwSetWindowUserPointer(HWINDOW, this);
}

Window::~Window()
{
        glfwDestroyWindow(HWINDOW);
        created_window_count--;

        if (created_window_count == 0)
                glfwTerminate();
}

bool Window::should_close()
{
        return glfwWindowShouldClose(HWINDOW);
}

void Window::set_size(int w, int h)
{
        glfwSetWindowSize(HWINDOW, w, h);
}

void Window::set_size_callback(PFN_WindowSizeCallback v_size_callback)
{
        fn_size_callback = v_size_callback;
        glfwSetWindowSizeCallback(HWINDOW, [](GLFWwindow *hwind, int w, int h) {
                Window *window = (Window *) glfwGetWindowUserPointer(hwind);
                window->fn_size_callback(window, w, h);
        });
}

void Window::get_size(int *w, int *h)
{
        glfwGetWindowSize(HWINDOW, w, h);
}