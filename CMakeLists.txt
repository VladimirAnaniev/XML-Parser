cmake_minimum_required(VERSION 3.6)
project(XML_Parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/FileManager/FileManager.cpp src/FileManager/FileManager.h src/Console/Console.cpp src/Console/Console.h src/FileManager/File/File.cpp src/FileManager/File/File.h src/Parser/Parser.cpp src/Parser/Parser.h src/Node/Node.cpp src/Node/Node.h src/Node/Argument/Argument.cpp src/Node/Argument/Argument.h src/String/String.cpp src/String/String.h)
add_executable(XML_Parser ${SOURCE_FILES})