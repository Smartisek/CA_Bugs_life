cmake_minimum_required(VERSION 3.21)
project(CA_bugs_life)

set(CMAKE_CXX_STANDARD 11)

add_executable(sfml_002 main.cpp
        Bug.h
        Bug.cpp
        Crawler.h
        Crawler.cpp
        Hopper.h
        Hopper.cpp
        Board.h
        Board.cpp
        Slider.h
        Slider.cpp
        MainMenu.h
        MainMenu.cpp
        SuperBug.h
        SuperBug.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(sfml_002 sfml-system sfml-window sfml-graphics sfml-audio)
