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
#include "RenderDriver.h"
// std
#include <vector>

RenderDriver::RenderDriver(Window *v_Window)
        : window(v_Window)
{
        CreateInstance();
        CreateSurface();
}

RenderDriver::~RenderDriver()
{
        vkDestroySurfaceKHR(instance, surface, NULL);
        vkDestroyInstance(instance, NULL);
}

////////////////////////////////////////////////////////////////////
/// Create Vulkan context handle.
////////////////////////////////////////////////////////////////////

void RenderDriver::CreateInstance()
{
        VkResult U_ASSERT_ONLY err;

        uint32_t extCount;
        vkEnumerateInstanceExtensionProperties(NULL, &extCount, NULL);
        std::vector<VkExtensionProperties> extProperties(extCount);
        vkEnumerateInstanceExtensionProperties(NULL, &extCount, std::data(extProperties));

        printf("Vulkan实例可用扩展属性列表\n");
        for (const auto item : extProperties)
                printf("  * %s %d\n", item.extensionName, item.specVersion);

        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, NULL);
        std::vector<VkLayerProperties> layerProperties(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, std::data(layerProperties));

        printf("Vulkan实例可用层列表\n");
        for (const auto item : layerProperties)
                printf("  * %s %d\n", item.layerName, item.specVersion);

        VkApplicationInfo applicationInfo = {
            /* sType= */ VK_STRUCTURE_TYPE_APPLICATION_INFO,
            /* pNext= */ NULL,
            /* pApplicationName= */ "Capture Engine",
            /* applicationVersion= */ VK_MAKE_VERSION(1, 0, 0),
            /* pEngineName= */ "Capture Engine",
            /* engineVersion= */ VK_MAKE_VERSION(1, 0, 0),
            /* apiVersion= */ VK_API_VERSION_1_3
        };

        std::vector<const char *> extensions = {
            "VK_KHR_surface",
            "VK_KHR_win32_surface",
        };

        VkInstanceCreateInfo instanceCreateInfo = {
            /* sType= */ VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            /* pNext= */ NULL,
            /* flags= */ 0,
            /* pApplicationInfo= */ &applicationInfo,
            /* enabledLayerCount= */ 0,
            /* ppEnabledLayerNames= */ NULL,
            /* enabledExtensionCount= */ (uint32_t) std::size(extensions),
            /* ppEnabledExtensionNames= */ std::data(extensions),
        };

        err = vkCreateInstance(&instanceCreateInfo, NULL, &instance);
        assert(!err);
}

void RenderDriver::CreateSurface()
{
        VkResult U_ASSERT_ONLY err;
        err = window->vkCreateSurfaceKHR(instance, NULL, &surface);
        assert(!err);
}