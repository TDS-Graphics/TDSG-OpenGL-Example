#ifndef TDSG_OPENGL_EXAMPLE_APP_BASE_H
#define TDSG_OPENGL_EXAMPLE_APP_BASE_H

#define GLM_ENABLE_EXPERIMENTAL

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/std_based_type.hpp>
#include <string>

namespace tds {

class app_base {
 public:
  app_base();

  void set_app_name(std::string app_name);
  std::string get_app_name();

  void set_wnd_title(std::string wnd_title);
  std::string get_wnd_title();

  void set_wnd_size(glm::size2 wnd_size);
  glm::size2 get_wnd_size();

  bool create();
  bool destroy();

  bool should_close();

  static void resize_callback(GLFWwindow* wnd_handle, int width, int height);

  void process_input();

 private:
  std::string m_app_name;
  std::string m_wnd_title;
  glm::size2 m_wnd_size{};

  GLFWwindow* m_wnd_handle{};
};

}  // namespace tds

#endif  // TDSG_OPENGL_EXAMPLE_APP_BASE_H
