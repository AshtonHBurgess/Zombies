cmake_minimum_required(VERSION 3.24)
project(ZombiesWithVectors2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZombiesWithVectors2 main.cpp City.cpp City.h Human.cpp Human.h Zombie.cpp Zombie.h Organism.cpp Organism.h GameSpecs.h)
