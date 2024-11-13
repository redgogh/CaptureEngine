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

// Window callbacks
typedef void (*PFN_WindowSizeCallback) (Window *window, int w, int h);

class Window {
public:
        Window(const char *title, int w, int h);
       ~Window();

        bool ShouldClose();
        void PollEvents();

#ifdef VK_VERSION_1_0
        VkResult vkCreateSurfaceKHR(VkInstance instance, const VkAllocationCallbacks* allocator, VkSurfaceKHR *pSurface)
        {
                return glfwCreateWindowSurface(instance, HWINDOW, allocator, pSurface);
        }
#endif

        void GetSize(int *w, int *h);
        GLFWwindow *GetWindowHandle() { return HWINDOW; }

        void SetSize(int w, int h);
        void SetVisible(bool isVisible);

        void SetSizeCallback(PFN_WindowSizeCallback windowSizeCallback);

        bool IsVisible() { return isVisibleFlag; }

private:
        bool isVisibleFlag = 0;
        GLFWwindow *HWINDOW = NULL;

        PFN_WindowSizeCallback fnWindowSizeCallback = NULL;

};
