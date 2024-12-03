cmake_minimum_required(VERSION 3.29)
project(EndangeredSpecies)

set(CMAKE_CXX_STANDARD 20)

add_executable(EndangeredSpecies BST.cpp BST.hpp BSTNode.cpp BSTNode.hpp EndangeredSpeciesmain.cpp Interface.cpp Interface.hpp Species.cpp Species.hpp
        EndangeredSpeciesmain.cpp)
