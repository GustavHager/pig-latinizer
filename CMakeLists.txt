CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0 FATAL_ERROR)

PROJECT(translator CXX)

ADD_SUBDIRECTORY(gtest)
ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES(./include)

find_package(Threads)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread" )

ADD_EXECUTABLE(translator src/translator_app.cpp src/Translator.cpp)
target_compile_features(translator PRIVATE cxx_range_for)
TARGET_LINK_LIBRARIES(translator ${CMAKE_THREAD_LIBS_INIT})

ADD_EXECUTABLE(translator_test test/translator_test.cpp src/Translator.cpp)
target_compile_features(translator_test PRIVATE cxx_range_for)
TARGET_LINK_LIBRARIES(translator_test ${CMAKE_THREAD_LIBS_INIT} gtest gtest_main)
