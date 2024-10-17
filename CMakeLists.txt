cmake_minimum_required(VERSION 3.23)

# 设置工具链文件路径
#set(CMAKE_TOOLCHAIN_FILE "D:/study/PLAYGROUND/C++/C++/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(A2)

set(CMAKE_CXX_STANDARD 14)

# 添加 nlohmann_json 的安装路径
#set(CMAKE_PREFIX_PATH "D:/study/PLAYGROUND/C++/C++/vcpkg/installed/x64-windows")

add_executable(A2 main.cpp fuzzylogic.h fuzzylogic.cpp transform.cpp transform.h sprites.cpp)

# 查找 nlohmann_json 包
#find_package(nlohmann_json CONFIG REQUIRED)

# 链接 nlohmann_json 库
#target_link_libraries(A2 PRIVATE nlohmann_json::nlohmann_json)
