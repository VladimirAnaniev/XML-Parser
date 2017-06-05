cmake_minimum_required(VERSION 3.6)
project(XML_Parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Console/Console.cpp src/Console/Console.h src/FileManager/File/File.cpp src/FileManager/File/File.h src/Parser/Parser.cpp src/Parser/Parser.h "src/XML Tree/XML_Node.cpp" "src/XML Tree/XML_Node.h" "src/XML Tree/Argument/Argument.cpp" "src/XML Tree/Argument/Argument.h" "src/Data Structures/String/String.cpp" "src/Data Structures/String/String.h" "src/Data Structures/Array/List.h" src/Dispatcher/Dispatcher.cpp src/Dispatcher/Dispatcher.h src/Dispatcher/Command/Command.cpp src/Dispatcher/Command/Command.h src/Utils/Globals.h "src/Data Structures/Tree/TreeNode.h" "src/Data Structures/Pair/Pair.h" "src/XML Tree/XML_Node.cpp" "src/XML Tree/XML_Node.h" "src/Data Structures/Tree/TreeNode.cpp" src/Interfaces/Stringifiable.h src/Utils/Exception.h src/FileManager/FileManager.cpp src/FileManager/FileManager.h)
add_executable(XML_Parser ${SOURCE_FILES})