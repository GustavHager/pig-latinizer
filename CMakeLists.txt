CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(translator)

ENABLE_TESTING()
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(./include)

ADD_EXECUTABLE(translator src/translator_app.cpp src/Translator.cpp)


ADD_EXECUTABLE(translator_test test/translator_test.cpp src/Translator.cpp)
TARGET_LINK_LIBRARIES(translator_test ${GTEST_BOTH_LIBRARIES})
