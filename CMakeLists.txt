# 指定CMake的最低版本和项目信息
cmake_minimum_required(VERSION 3.15)
project(my_audio_video_project CXX)

# 设置C++标准为C++17，这是现代C++的推荐标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 这一行依然关键，用于生成 clangd 需要的文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加你的可执行文件目标
add_executable(1.cpp)