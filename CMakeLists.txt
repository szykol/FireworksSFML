cmake_minimum_required(VERSION 3.8.2)
project(Fireworks)

add_executable(fireworks 
    src/Firework.cpp
    src/Source.cpp
    src/Particle.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED graphics window system audio)
set(CMAKE_CXX_STANDARD 17)

file(COPY Sounds DESTINATION ${CMAKE_BINARY_DIR})
target_link_libraries(fireworks ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
