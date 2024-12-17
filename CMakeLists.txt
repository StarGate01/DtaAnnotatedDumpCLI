cmake_minimum_required(VERSION 3.10)

set(PROJECT DtaAnnotatedDumpCLI)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(SEDUTIL_PATH ${CMAKE_CURRENT_LIST_DIR}/sedutil)

project(${PROJECT} VERSION 1.0.0 LANGUAGES CXX C ASM)
add_subdirectory(src)