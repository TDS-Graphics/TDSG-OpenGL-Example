#include <iostream>

#include "app_base.h"

int main(int argc, char* argv[]) {
  std::cout << "----------== TDS Graphics Group ==----------" << std::endl;

  tds::app_base app{};
  app.set_app_name("TDS Graphics Group Application");
  app.set_wnd_title("TDS Graphics Group OpenGL Example");
  app.set_wnd_size({1920, 1080});

  app.create();

  while (!app.should_close()) {
    app.should_close();
  }

  app.destroy();

  return 0;
}