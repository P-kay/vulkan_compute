#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>


int init_vk_instance(VkInstance *instance, char *name) {
    int errcode = 0;

    // vulkan application info
    VkApplicationInfo appinfo = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = name,
        .apiVersion = VK_API_VERSION_1_0                // only this matters
    };

    // vulkan instance info
    VkInstanceCreateInfo vkinfo = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &appinfo                    // only this matters
    };

    // create an instance
    if (VK_SUCCESS != vkCreateInstance(&vkinfo, NULL, instance)) {
        fprintf(stderr, "Failed to create instance.\n");
        errcode = -1;
        goto failout;
    }

failout:
    return errcode;
}


int main() {
    // create vulkan instance
    VkInstance instance;
    if (-1 == init_vk_instance(&instance, "Compute Demo")) {
        goto failout_inst;
    }
    
//    // get the number of physical devices
//    uint32_t physicalDeviceCount = 0;
//    vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, 0);
//    printf("Physical Devices Found: %d\n", physicalDeviceCount);
//
//    // fill array with handles to the physical devices
//    VkPhysicalDevice *phys_devices = 
//        (VkPhysicalDevice *)malloc(sizeof(VkPhysicalDevice) * physicalDeviceCount);
//    vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, phys_devices);
//
//    // get physical device properties
//    VkPhysicalDeviceProperties properties;
//    vkGetPhysicalDeviceProperties(phys_devices[0], &properties);
//    printf(
//        "Properties:\n"
//        "    Device Type: %d\n"
//        "    Device Name: %s\n"
//        "    Shared Mem Size: %d Bytes\n"
//    , properties.deviceType, properties.deviceName, properties.limits.maxComputeSharedMemorySize);
//
//    // find the number of queue families
//    uint32_t queueFamilyPropertiesCount = 0;
//    vkGetPhysicalDeviceQueueFamilyProperties(
//            phys_devices[0], &queueFamilyPropertiesCount, 0);
//    printf("Queue Families Found: %d\n", queueFamilyPropertiesCount);
//
//    // populate an array of queue family properties
//    VkQueueFamilyProperties *q_family_properties = 
//        (VkQueueFamilyProperties *)malloc(
//                sizeof(VkQueueFamilyProperties) * queueFamilyPropertiesCount);
//    vkGetPhysicalDeviceQueueFamilyProperties(phys_devices[0],
//            &queueFamilyPropertiesCount, q_family_properties);
//
//    // find a valid index
//    int valid_q_idx = 0;
//    for (int i = 0; i < queueFamilyPropertiesCount; i++) {
//        if (((q_family_properties[i].queueFlags & 3) ^ 2) == 0) {
//            printf("    Compute Index: %d, %x\n", i, q_family_properties[i].queueFlags);
//            valid_q_idx = i;
//            continue;
//        }
//    }
//    
//    // create device queue info
//    const float q_priority = 1.0f;
//    VkDeviceQueueCreateInfo device_q_create_info = {
//        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
//        .queueFamilyIndex = valid_q_idx,
//        .queueCount = 1,
//        .pQueuePriorities = &q_priority
//    };
//
//    // create device info
//    VkDeviceCreateInfo device_create_info = {
//        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
//        .queueCreateInfoCount = 1,
//        .pQueueCreateInfos = &device_q_create_info
//    };
//
//    // create the device
//    VkDevice device;
//    vkCreateDevice(phys_devices[0], &device_create_info, 0, &device);
//
//    // get the device queue
//    VkQueue queue;
//    vkGetDeviceQueue(device, valid_q_idx, 0, &queue);
//    
//
failout:
//    vkDestroyDevice(device, NULL);
failout_inst:
    vkDestroyInstance(instance, NULL);
//    
//    free(phys_devices);
//    free(q_family_properties);
    printf("Exit!\n");
    return 0;
}
