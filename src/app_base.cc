#include "app_base.h"

#include <iostream>
#include <ostream>
#include <utility>

namespace tds {

app_base::app_base() {
  this->m_app_name = "App";
  this->m_wnd_title = "App Title";
  this->m_wnd_size = {640, 480};
}

void app_base::set_app_name(std::string app_name) {
  this->m_app_name = std::move(app_name);
}
std::string app_base::get_app_name() { return this->m_app_name; }

void app_base::set_wnd_title(std::string wnd_title) {
  this->m_wnd_title = std::move(wnd_title);
}
std::string app_base::get_wnd_title() { return this->m_wnd_title; }

void app_base::set_wnd_size(glm::size2 wnd_size) {
  this->m_wnd_size = wnd_size;
}
glm::size2 app_base::get_wnd_size() { return this->m_wnd_size; }

bool app_base::create() {
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->m_wnd_handle =
      glfwCreateWindow(this->m_wnd_size.x, this->m_wnd_size.y,
                       this->m_wnd_title.c_str(), nullptr, nullptr);
  if (this->m_wnd_handle == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(this->m_wnd_handle);
  glfwSetFramebufferSizeCallback(this->m_wnd_handle, resize_callback);

  return true;
}
bool app_base::destroy() {
  glfwDestroyWindow(this->m_wnd_handle);
  glfwTerminate();

  return true;
}

bool app_base::should_close() {
  return glfwWindowShouldClose(this->m_wnd_handle);
}

void app_base::resize_callback(GLFWwindow* wnd_handle, int width, int height) {
  // glViewport(0, 0, width, height);
}

void app_base::process_input() {
  if (glfwGetKey(this->m_wnd_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(this->m_wnd_handle, true);
  }
}

}  // namespace tds