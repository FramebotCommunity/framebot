cmake_minimum_required (VERSION 3.7)
project(framebotLibrary)

include_directories (${PROJECT_SOURCE_DIR}/../include)

# Search for the required libraries, erroring out if they aren't found
find_library(JANSSON_LIB NAMES jansson)
find_package(CURL REQUIRED)
# Add the include directories for the libraries
include_directories(${CURL_INCLUDE_DIRS})

if(UNIX)
	if(NOT CMAKE_SYSTEM_NAME STREQUAL Linux AND NOT CMAKE_SYSTEM_NAME STREQUAL FreeBSD)
		# This is probably an unsupported BSD or OSX.
		# Show an error, but try to proceed.
		message(SEND_ERROR "Only Linux, FreeBSD and Windows are supported at this time.")
	endif()


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


	add_library(framebot_ SHARED framebot.c memory.c objects.c json.c network.c format.c util.c payments.c)
	target_link_libraries(framebot_ ${JANSSON_LIB} ${curl})

	add_library(framebot STATIC framebot.c memory.c objects.c json.c network.c format.c util.c payments.c)
	target_link_libraries(framebot ${JANSSON_LIB} ${curl})

	install(TARGETS framebot_ LIBRARY DESTINATION lib)
	install(TARGETS framebot ARCHIVE DESTINATION lib)

endif()

if(WIN32)
	add_library(framebot framebot.c memory.c objects.c json.c network.c format.c util.c payments.c)
	target_link_libraries(framebot ${JANSSON_LIB} ${CURL_LIBRARIES})
	install(TARGETS framebot ARCHIVE DESTINATION lib)
endif()
