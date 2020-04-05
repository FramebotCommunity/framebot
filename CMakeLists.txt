cmake_minimum_required (VERSION 3.7)
project(FramebotFramework)

find_package(OpenSSL REQUIRED)


	if(DEBUG EQUAL 1)
		message(STATUS "DEBUG active")
		add_definitions("-g")
		add_definitions("-Wall")
	endif()

	if(GPROF EQUAL 1)
		message(STATUS "GPROF active")
		add_definitions("-pg")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
		SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
		SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
	endif()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)

install(DIRECTORY include/ DESTINATION include)

#include(CPack) # Create installation package