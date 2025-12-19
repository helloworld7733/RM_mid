cmake_minimum_required(VERSION 3.10)

project(StanceDetection_sys CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Detection 
    src/main.cpp 
    src/Lexicon.cpp 
    src/Negword.cpp 
    src/Preprocess.cpp 
    src/StanceDetection.cpp 
    src/Tokenizer.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
