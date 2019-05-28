##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

if(NOT DEFINED(${LIBVIREG_BUILD_EXAMPLES}))
  set(LIBVIREG_BUILD_EXAMPLES yes)
endif()

##########################################################################

set(VIREG_LIBRARY_TARGET vireg)

##########################################################################

include_directories(include)
include_directories(external/json/current/include)

##########################################################################

set(CMAKE_CXX_STANDARD 11)

##########################################################################

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

##########################################################################

set(VIREG_LIBRARY_SRC_PATH src)

set(VIREG_LIBRARY_SRCS
  ${VIREG_LIBRARY_SRC_PATH}/VirtualRegisterLoader.cpp
  ${VIREG_LIBRARY_SRC_PATH}/VirtualRegisterMap.cpp
)

##########################################################################

add_library(
  ${VIREG_LIBRARY_TARGET}
  STATIC
  ${VIREG_LIBRARY_SRCS}
)

##########################################################################

if(${LIBVIREG_BUILD_EXAMPLES} STREQUAL "yes")
  add_subdirectory(examples)
endif()

##########################################################################
