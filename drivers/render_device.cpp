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
#include "render_device.h"

RenderDevice::RenderDevice(Window *p_window)
        : window(p_window)
{
        _create_instance();
        _create_surface();
}

RenderDevice::~RenderDevice()
{
        vkDestroySurfaceKHR(inst, surface, NULL);
        vkDestroyInstance(inst, NULL);
}

void RenderDevice::_create_instance()
{
        VkResult U_ASSERT_ONLY err;

        uint32_t extcunt = 0;
        err = vkEnumerateInstanceExtensionProperties(NULL, &extcunt, NULL);
        assert(!err);

        std::vector<VkExtensionProperties> extvec(extcunt);
        err = vkEnumerateInstanceExtensionProperties(NULL, &extcunt, std::data(extvec));
        assert(!err);

        printf("[vulkan] vulkan extension properties list for instance\n");
        for (const auto ext : extvec)
                printf("  * %s %d\n", ext.extensionName, ext.specVersion);

        VkApplicationInfo application_info = {};
        application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        application_info.pNext = NULL;
        application_info.pApplicationName = "capture";
        application_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        application_info.pEngineName = "capture";
        application_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        application_info.apiVersion = VK_API_VERSION_1_3;

        std::vector<const char *> extensions = {
                "VK_KHR_win32_surface",
                "VK_KHR_surface",
        };

        VkInstanceCreateInfo instance_ci = {};
        instance_ci.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instance_ci.pNext = NULL;
        instance_ci.flags = 0;
        instance_ci.pApplicationInfo = &application_info;
        instance_ci.enabledLayerCount = 0;
        instance_ci.ppEnabledLayerNames = NULL;
        instance_ci.enabledExtensionCount = (uint32_t) std::size(extensions);
        instance_ci.ppEnabledExtensionNames = std::data(extensions);

        err = vkCreateInstance(&instance_ci, NULL, &inst);
        assert(!err);
}

void RenderDevice::_create_surface()
{
        VkResult U_ASSERT_ONLY err;
        err = window->vk_create_surface(inst, NULL, &surface);
        assert(!err);
}