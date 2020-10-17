cmake_minimum_required(VERSION 3.11)

set(APP_VERSION "0.1.0")

project(cyrillic-pad VERSION "${APP_VERSION}")

set(CMAKE_VERBOSE_MAKEFILE OFF)
if(NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# enable qt moc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# modules
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
# Find Qt5
find_package(Qt5 COMPONENTS Widgets Core Gui Svg REQUIRED)

# include headers
include_directories("include")

# client files
FILE(GLOB_RECURSE CLIENT_SRC
	"src/*"
	"include/*"
)

add_definitions( -DAPP_VERSION="${APP_VERSION}" )

add_executable(cyrillic-pad
	${CLIENT_SRC}
)

# client link
target_link_libraries(cyrillic-pad
	Qt5::Svg
	Qt5::Widgets)

file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})
file(COPY "css" DESTINATION ${CMAKE_BINARY_DIR})