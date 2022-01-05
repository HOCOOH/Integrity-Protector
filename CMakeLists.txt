# cmake最小版本要求
cmake_minimum_required(VERSION 3.5.1)

# 项目名称
project(IntegrityProtector)

# 设置C++编译标准
set(CMAKE_CXX_STANDARD 14)

# 添加include位置
include_directories(src)

# 生成可执行文件
add_executable( IntegrityProtector
    src/main.cpp
    src/SM3.cpp
)
