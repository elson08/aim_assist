cmake_minimum_required(VERSION 3.30)

if(WIN32 AND NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
	find_program(AIM_ASSIST_CLANG_CL clang-cl REQUIRED)
	set(CMAKE_C_COMPILER "${AIM_ASSIST_CLANG_CL}" CACHE FILEPATH "" FORCE)
	set(CMAKE_CXX_COMPILER "${AIM_ASSIST_CLANG_CL}" CACHE FILEPATH "" FORCE)
endif()

if(WIN32 AND NOT DEFINED CMAKE_MT)
	file(GLOB AIM_ASSIST_WINDOWS_SDK_BIN_DIRS LIST_DIRECTORIES true "C:/Program Files (x86)/Windows Kits/10/bin/*/x64")
	list(SORT AIM_ASSIST_WINDOWS_SDK_BIN_DIRS COMPARE NATURAL ORDER DESCENDING)
	find_program(CMAKE_MT mt HINTS ${AIM_ASSIST_WINDOWS_SDK_BIN_DIRS} REQUIRED)
endif()

project(aim_assist LANGUAGES C CXX)

if(NOT WIN32)
	message(FATAL_ERROR "aim_assist only supports Windows.")
endif()

if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
	message(FATAL_ERROR "aim_assist requires clang-cl.")
endif()

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

include(cmake/CPM.cmake)

CPMAddPackage(
	NAME libhat
	GITHUB_REPOSITORY BasedInc/libhat
	GIT_TAG 56a56728f6ba92aa58b5b567ec10f15d258bf571
)

target_compile_definitions(libhat PUBLIC
	_ITERATOR_DEBUG_LEVEL=0
	_HAS_ITERATOR_DEBUGGING=0
)

CPMAddPackage(
	NAME EnTT
	GITHUB_REPOSITORY skypjack/entt
	GIT_TAG 49904e65d7fb1de680e80995b510c0d6912e2f94
)

CPMAddPackage(
	NAME glm
	GITHUB_REPOSITORY g-truc/glm
	GIT_TAG 1.0.3
)

CPMAddPackage(
	NAME GSL
	GITHUB_REPOSITORY microsoft/GSL
	GIT_TAG v4.2.2
)

CPMAddPackage(
	NAME safetyhook
	GITHUB_REPOSITORY cursey/safetyhook
	GIT_TAG v0.7.0
)

target_compile_definitions(safetyhook PUBLIC
	_ITERATOR_DEBUG_LEVEL=0
	_HAS_ITERATOR_DEBUGGING=0
)

file(GLOB_RECURSE AIM_ASSIST_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library(aim_assist SHARED ${AIM_ASSIST_SOURCES})

target_include_directories(aim_assist PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_precompile_headers(aim_assist PRIVATE src/pch.h)

target_compile_features(aim_assist PRIVATE cxx_std_23)

target_compile_definitions(aim_assist PRIVATE
	_ITERATOR_DEBUG_LEVEL=0
	_HAS_ITERATOR_DEBUGGING=0
)

target_link_libraries(aim_assist PRIVATE
	EnTT::EnTT
	Microsoft.GSL::GSL
	glm::glm
	libhat::libhat
	safetyhook::safetyhook
)
