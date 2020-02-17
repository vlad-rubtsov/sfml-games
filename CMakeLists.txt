cmake_minimum_required(VERSION 3.1)

set(This game)


project(${This})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(SFML_STATIC_LIBRARIES TRUE)

# Find SFML
# Note: SFML_STATIC_LIBRARIES determines which libraries are found by find_package()
find_package(SFML 2 COMPONENTS audio graphics window system network)


set(CoreSources
	main.cpp
	Game.cpp
	Window.cpp
)

set(PlatformerGameSources
	PlatformerGame.cpp
	Player.cpp
)

set(CommonLibs
	Threads::Threads
	sfml-graphics
	sfml-window
	sfml-system
)



add_executable(${This} ${CoreSources} ${PlatformerGameSources})
add_executable(platformer ${CoreSources} ${PlatformerGameSources})

target_link_libraries(${This} PUBLIC ${CommonLibs})
target_link_libraries(platformer PUBLIC ${CommonLibs})
