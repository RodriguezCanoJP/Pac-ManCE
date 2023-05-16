cmake_minimum_required(VERSION 3.25)
project(Pac_ManCE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pac_ManCE
        Jugador.cpp
        Headers/Jugador.h
        Main.cpp
        DrawMap.cpp
        Headers/Variables.h
        Variables.cpp Headers/Enemigo.h Enemigo.cpp Backtracking.cpp Arbol.cpp Headers/astar.h astar.cpp Headers/powerMod.h powerMod.cpp)

target_include_directories(Pac_ManCE PUBLIC /usr/include/SFML )
target_link_libraries(Pac_ManCE sfml-system sfml-window sfml-graphics)