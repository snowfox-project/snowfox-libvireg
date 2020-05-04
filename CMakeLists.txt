##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

set(VIREG_LIBRARY_TARGET vireg)

##########################################################################

include_directories(include)

##########################################################################

add_subdirectory(external/json/current)

##########################################################################

set(CMAKE_CXX_STANDARD 17)

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

target_link_libraries(${VIREG_LIBRARY_TARGET} json)

##########################################################################

target_include_directories(${VIREG_LIBRARY_TARGET} PUBLIC include)

##########################################################################

if(DEFINED(${LIBVIREG_BUILD_EXAMPLES}))
  if(${LIBVIREG_BUILD_EXAMPLES} STREQUAL "yes")
    add_subdirectory(examples)
  endif()
endif()

##########################################################################
