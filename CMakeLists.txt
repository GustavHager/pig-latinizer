CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0 FATAL_ERROR)

PROJECT(translator CXX)

ADD_SUBDIRECTORY(gtest)
ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES(./include)

ADD_SUBDIRECTORY(src/CLP)
INCLUDE_DIRECTORIES(src/CLP)

find_package(Threads)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread" )

ADD_EXECUTABLE(inverse_translator src/inv_translator_app.cpp src/InverseTranslator.cpp src/PigLatinTranslator.cpp)

ADD_EXECUTABLE(translator src/translator_app.cpp src/PigLatinTranslator.cpp src/InverseTranslator.cpp src/TranslatorGUI.cpp)
TARGET_LINK_LIBRARIES(translator CLP)
TARGET_LINK_LIBRARIES(translator ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(translator PRIVATE cxx_range_for)

# Find and link to SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(translator ${SFML_LIBRARIES})
else()
  message (WARNING "Did not find SFML")
endif()
find_package(TGUI REQUIRED)
if(TGUI_FOUND)
  include_directories(${TGUI_INCLUDE_DIR})
  target_link_libraries(translator ${TGUI_LIBRARY})
else()
  message (WARNING "Did not find TGUI")
endif()

ADD_EXECUTABLE(translator_test test/translator_test.cpp src/PigLatinTranslator.cpp src/InverseTranslator.cpp)
target_compile_features(translator_test PRIVATE cxx_range_for)
TARGET_LINK_LIBRARIES(translator_test ${CMAKE_THREAD_LIBS_INIT} gtest gtest_main)

