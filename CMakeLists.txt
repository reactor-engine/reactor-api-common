cmake_minimum_required(VERSION 3.0)
project(reactor_api_common)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -flto")

set(SOURCE_FILES
        api/include/reactor/common/type/floats.hpp
        api/include/reactor/common/type/integers.hpp
        api/include/reactor/common/type/relative.hpp
        api/include/reactor/common/type/types.hpp
        api/include/reactor/common/injector.hpp)

#add_executable(reactor_api_common ${SOURCE_FILES})
