cmake_minimum_required( VERSION 3.12 )
project( QRScanner )

# Compiler and flags
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )

# Set directories
set( INCLUDE_DIR include )

# Set include and libraries based on OS
if( APPLE )
	set( EXT_INCLUDE /opt/homebrew/include )
	set( EXT_LIBS /opt/homebrew/lib )
else()
	set (EXT_INCLUDE /usr/include )
	set (EXIT_LIBS /usr/lib )
endif()

# Find OpenCV
find_package( OpenCV REQUIRED )

# Include proper directories
include_directories( 
	${EXT_INCLUDE}
	${INCLUDE_DIR}
)

# Set external libs
link_directories(
	${EXT_LIBS}
)

# Set output binary directory
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

# Executable
add_executable( QRScanner src/main.cpp src/QRScanner.cpp )

# Link external libraries
target_link_libraries( QRScanner zbar ${OpenCV_LIBS} )
