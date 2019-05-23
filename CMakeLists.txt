##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

set(BUILD_EXAMPLES yes)

##########################################################################

set(VIREG_LIBRARY_TARGET vireg)

##########################################################################

include_directories(include)
include_directories(external/json/current/include)

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

if(${BUILD_EXAMPLES} STREQUAL "yes")
  add_subdirectory(examples)
endif()

##########################################################################