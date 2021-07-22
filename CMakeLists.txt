cmake_minimum_required(VERSION 3.17)

project(ProjectTemaplate)

include(FetchContent)
set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(TMXLITE_STATIC_LIB TRUE)
    SET(CMAKE_EXE_LINKER_FLAGS "-static")
endif(WIN32)
#
# Install SFML if not installed
#
set(SFML_VERSION "2.5.1")
find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics QUIET)

if (NOT SFML_FOUND)
    message(STATUS "SFML not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            sfml
            URL https://github.com/SFML/SFML/releases/download/${SFML_VERSION}/SFML-${SFML_VERSION}-sources.zip
    )

    FetchContent_GetProperties(sfml)
    if(NOT sfml_POPULATED)
        FetchContent_Populate(sfml)
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()
endif()


#
# Install TMXLITE if not installed
#
find_package(TMXLITE QUIET)

if (NOT ${TMXLITE_FOUND})
    message(STATUS "tmxlite not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            tmxlite
            GIT_REPOSITORY https://github.com/fallahn/tmxlite
            GIT_TAG        v1.2.1
    )
    FetchContent_MakeAvailable(tmxlite)
    add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite)
    set(TMXLITE_LIBRARIES tmxlite)
    set(TMXLITE_INCLUDE_DIR ${tmxlite_SOURCE_DIR}/tmxlite/include)
endif()





add_executable(${PROJECT_NAME} src/main.cpp include/Ball.cpp include/Ball.h include/manager/TextureManager.cpp include/manager/TextureManager.h include/Player.cpp include/Player.h include/Game.cpp include/Game.h include/manager/CollisionManager.h include/State.cpp include/State.h include/StateMachine.cpp include/StateMachine.h include/state/MenuState.cpp include/state/MenuState.h Constants.h include/manager/AssetManager.cpp include/manager/AssetManager.h include/manager/InputManager.cpp include/manager/InputManager.h include/state/GameState.cpp include/state/GameState.h include/manager/SoundManager.cpp include/manager/SoundManager.h include/state/PauseState.cpp include/state/PauseState.h include/Powerup.h include/Powerup.cpp include/PowerupFactory.cpp include/PowerupFactory.h include/powerup/PowerupInvisible.cpp include/powerup/PowerupInvisible.h include/powerup/PowerupBigBase.cpp include/powerup/PowerupBigBase.h include/powerup/PowerupSmallBall.cpp include/powerup/PowerupSmallBall.h include/powerup/PowerupSmallBase.cpp include/powerup/PowerupSmallBase.h include/brick/MapBrick.cpp include/brick/MapBrick.h include/brick/Brick.cpp include/brick/Brick.h include/brick/BrickFactory.h include/brick/BrickFactory.cpp include/brick/BrickFactory.h include/brick/BrokenBrick.cpp include/brick/BrokenBrick.h include/brick/BrickInterface.cpp include/brick/BorderBrick.h include/brick/BorderBrick.cpp include/brick/BrickInterface.h include/PlayerShooter.cpp include/PlayerShooter.h include/Bullet.cpp include/Bullet.h include/powerup/PowerupBaseShoot.cpp include/powerup/PowerupBaseShoot.h include/manager/animation/AnimationManager.cpp include/manager/animation/AnimationManager.h include/manager/animation/Container.cpp include/manager/animation/Container.h include/state/GameOverState.cpp include/state/GameOverState.h include/manager/ActionManager.cpp include/manager/CollisionManager.cpp)

if (WIN32)
    include_directories(
            ${TMXLITE_INCLUDE_DIR}
            ${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            sfml-audio-d
            sfml-graphics
            sfml-system
            sfml-window
            ${TMXLITE_LIBRARIES}
            )
else()
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            sfml-audio
            sfml-graphics
            sfml-system
            sfml-window
            ${TMXLITE_LIBRARIES}
            )

endif (WIN32)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)


add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
