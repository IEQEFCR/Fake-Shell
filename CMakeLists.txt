cmake_minimum_required(VERSION 3.10)
# 设置项目名称
project(fake_shell)
# 添加可执行文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp ${DIR_SRCS})
target_link_libraries(main readline)
add_executable(ls ls.cpp ./src/tools.cpp)
add_executable(rm rm.cpp ./src/tools.cpp)
add_executable(cat cat.cpp)
add_executable(touch touch.cpp)
add_executable(mkdir mkdir.cpp)
add_executable(xargs xargs.cpp ${DIR_SRCS})
add_executable(ln ln.cpp ./src/tools.cpp)
add_executable(mv mv.cpp ./src/tools.cpp)
add_executable(cp cp.cpp ${DIR_SRCS})

target_link_libraries(main readline)
target_link_libraries(xargs readline)
target_link_libraries(cp readline)

set(EXECUTABLE_OUTPUT_PATH ./build)