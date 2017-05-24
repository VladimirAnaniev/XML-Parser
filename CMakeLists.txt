cmake_minimum_required(VERSION 3.6)
project(XML_Parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/FileManager/FileManager.cpp src/FileManager/FileManager.h src/Console/Console.cpp src/Console/Console.h src/FileManager/File/File.cpp src/FileManager/File/File.h src/Parser/Parser.cpp src/Parser/Parser.h src/Node/Node.cpp src/Node/Node.h src/Node/Argument/Argument.cpp src/Node/Argument/Argument.h "src/Base Classes/String/String.cpp" "src/Base Classes/String/String.h" "src/Base Classes/Array/Array.tpp" "src/Base Classes/Array/Array.h" src/Dispatcher/Dispatcher.cpp src/Dispatcher/Dispatcher.h src/Dispatcher/Command/Command.cpp src/Dispatcher/Command/Command.h src/Globals.h src/Node/Id/Id.cpp src/Node/Id/Id.h)
add_executable(XML_Parser ${SOURCE_FILES})