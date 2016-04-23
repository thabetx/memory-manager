set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

add_executable(main
 main.cpp
 Block.cpp
 Process.cpp
 Memory.cpp
 FirstFitMemory.cpp
 BestFitMemory.cpp
 WorstFitMemory.cpp
)
