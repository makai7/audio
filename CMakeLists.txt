# 指定CMake的最低版本和项目信息
cmake_minimum_required(VERSION 3.15)
project(my_audio_video_project CXX)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 生成 compile_commands.json 供 clangd 使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加你的可执行文件目标
# 格式: add_executable(程序名字 源文件名)
add_executable(wav_arduio day1.cpp)

find_package(ALSA REQUIRED)
target_link_libraries(wav_parser PRIVATE ${ALSA_LIBS})