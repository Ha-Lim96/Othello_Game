cmake_minimum_required( VERSION 3.0 )
project( Projet_reversi )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( PKG_CPPUTEST REQUIRED cpputest )
include_directories( ${PKG_CPPUTEST_INCLUDE_DIRS} )

# programme principal
add_executable( reversi-cli src/main.cpp
    src/Game.cpp )
target_link_libraries( reversi-cli )

# programme de test
add_executable( main_test.out src/main_test.cpp
    src/Game.cpp src/Game_test.cpp )
target_link_libraries( main_test.out ${PKG_CPPUTEST_LIBRARIES} )


