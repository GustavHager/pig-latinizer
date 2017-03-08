CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(translator)

ADD_SUBDIRECTORY(gtest)
ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES(./include)


ADD_SUBDIRECTORY(src/CLP)
INCLUDE_DIRECTORIES(src/CLP)


ADD_EXECUTABLE(translator src/translator_app.cpp src/Translator.cpp)
TARGET_LINK_LIBRARIES(translator CLP)


ADD_EXECUTABLE(translator_test test/translator_test.cpp src/Translator.cpp)
TARGET_LINK_LIBRARIES(translator_test gtest gtest_main)
