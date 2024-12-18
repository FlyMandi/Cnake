#pragma once

#include "vulkan/vulkan_core.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace engine {

class EngineWindow {
 public:
    EngineWindow(int w, int h, std::string name);
    ~EngineWindow();

    EngineWindow(const EngineWindow &) = delete;
    EngineWindow &operator=(const EngineWindow &) = delete;

    bool shouldClose() { return glfwWindowShouldClose(window); }

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

 private:
    void initWindow();
    const int width;
    const int height;

    std::string windowName;
    GLFWwindow *window;

};

}  // namespace engine
