cmake_minimum_required(VERSION 3.10)
# 设置项目名称
project(fake_shell)
# 添加可执行文件
add_executable(main shell.cpp tools.cpp main.cpp)
add_executable(ls ls.cpp tools.cpp)
add_executable(cat cat.cpp)
add_executable(rm rm.cpp tools.cpp)
add_executable(touch touch.cpp)
add_executable(mkdir mkdir.cpp )
add_executable(xargs xargs.cpp shell.cpp tools.cpp)
target_link_libraries(xargs readline)
target_link_libraries(main readline)

set(EXECUTABLE_OUTPUT_PATH ./build)