cmake_minimum_required(VERSION 2.8.8)
include(GNUInstallDirs)

project(inputsim)

option(SHARED "Build the shared library" ON)
option(STATIC "Build the static library" ON)

if(UNIX AND NOT APPLE)
    if(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
        set(LINUX TRUE)
    endif()
endif()

file(GLOB sources src/*.c)
if (WIN32)
	file(GLOB windows_sources src/windows/*.c)
	set(sources ${sources} ${windows_sources})
elseif(LINUX)
	file(GLOB linux_sources src/linux/*.c)
	set(sources ${sources} ${linux_sources})
else()
	message(FATAL_ERROR "Platform unsupported.")
endif()

if (NOT STATIC AND NOT SHARED)
	message(FATAL_ERROR "Nothing to build")
endif()

include_directories("include/" "src/")

add_library(objlib OBJECT ${sources})

set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)

if (SHARED)
	add_library(inputsim SHARED $<TARGET_OBJECTS:objlib>)
endif()

if (STATIC)
	add_library(inputsim_static STATIC $<TARGET_OBJECTS:objlib>)
endif()

message(STATUS "${CMAKE_BINARY_DIR}")
install(DIRECTORY "${CMAKE_SOURCES_DIR}/include/inputsim"
		DESTINATION "${CMAKE_BINARY_DIR}/include"
		FILES_MATCHING PATTERN "*.h"
)

install(TARGETS inputsim inputsim_static
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
