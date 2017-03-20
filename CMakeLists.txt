CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0 FATAL_ERROR)

PROJECT(translator CXX)

ADD_SUBDIRECTORY(gtest)
ENABLE_TESTING()
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES(./include)

ADD_SUBDIRECTORY(src/CLP)
INCLUDE_DIRECTORIES(src/CLP)

find_package(Threads)

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread" )

# Find and link to SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.3)
find_package(TGUI 0.7.3)

if(SFML_FOUND AND TGUI_FOUND)
  find_package(SFML 2.3 REQUIRED system window graphics network audio)
  SET( ENABLE_GRAPHICS TRUE ) 
else()
  if(NOT SFML_FOUND)
      message (WARNING "Did not find SFML")
  endif()

  if(NOT TGUI_FOUND)
      message(WARNING "Did not find TGUI")
  endif()

  message(WARNING "Disabling graphics")
  set(ENABLE_GRAPHICS FALSE)
endif()

# Translator app
if(ENABLE_GRAPHICS)
  ADD_EXECUTABLE(translator src/translator_app.cpp src/PigLatinTranslator.cpp src/InverseTranslator.cpp src/TranslatorGUI.cpp)
  add_definitions(-DENABLE_GRAPHICS)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(translator ${SFML_LIBRARIES})
  include_directories(${TGUI_INCLUDE_DIR})
  target_link_libraries(translator ${TGUI_LIBRARY})
else()
  ADD_EXECUTABLE(translator src/translator_app.cpp src/PigLatinTranslator.cpp src/InverseTranslator.cpp)
endif()

SET_PROPERTY(TARGET translator PROPERTY CXX_STANDARD 11)
TARGET_LINK_LIBRARIES(translator CLP ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(CLP PRIVATE cxx_range_for)
target_compile_features(translator PRIVATE cxx_range_for)

# TODO: remove
ADD_EXECUTABLE(inverse_translator src/inv_translator_app.cpp src/InverseTranslator.cpp src/PigLatinTranslator.cpp)
SET_PROPERTY(TARGET inverse_translator PROPERTY CXX_STANDARD 11)

# Tests
ADD_EXECUTABLE(translator_test test/translator_test.cpp src/PigLatinTranslator.cpp src/InverseTranslator.cpp)
SET_PROPERTY(TARGET translator_test PROPERTY CXX_STANDARD 11)
TARGET_LINK_LIBRARIES(translator_test ${CMAKE_THREAD_LIBS_INIT} gtest gtest_main)

# Copy resource files to build map
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

