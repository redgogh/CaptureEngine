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

#include <vulkan/vulkan.h>
#include "surface/window.h"
#include <capture/error.h>
// std
#include <vector>
#include <tuple>

class RenderDevice {
public:
        RenderDevice(Window *p_window);
       ~RenderDevice();

private:
        void _init_render_device();
        void _destroy_render_device();

        void _create_instance();
        void _create_surface();
        void _init_gpu_device();
        void _create_device();

private:
        Window *window;

        VkPhysicalDeviceProperties gpu_info;

        VkInstance inst = NULL;
        VkSurfaceKHR surface = NULL;
        VkPhysicalDevice gpu = NULL;
};