cmake_minimum_required(VERSION 4.2)
project(TDSG_OpenGL_Example)

set(CMAKE_CXX_STANDARD 23)

set(INCL_DIR include/)
set(SRC_DIR
        src/main.cc
        src/app_base.cc
)

# GLM
add_subdirectory(thirdparty/glm)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE STRING "" FORCE)
add_subdirectory(thirdparty/glfw)

include_directories(${INCL_DIR})
add_executable(${PROJECT_NAME} ${SRC_DIR})

target_link_options(${PROJECT_NAME} PRIVATE -static)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
