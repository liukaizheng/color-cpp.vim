file(GLOB SRC_FILES *.cpp)
add_library(clang_analyzer OBJECT ${SRC_FILES})
