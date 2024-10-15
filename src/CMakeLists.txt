cmake_minimum_required(VERSION 3.5)

project(3dViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL)
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)

include_directories(${CMAKE_SOURCE_DIR}/view)
include_directories(${CMAKE_SOURCE_DIR}/controller)
include_directories(${CMAKE_SOURCE_DIR}/model)
add_definitions(-DGL_SILENCE_DEPRECATION)

set(PROJECT_SOURCES
        main.cc
        view/application.cc
        view/application.h
        view/application.ui
        view/openglwidget.cc
        view/openglwidget.h
        controller/controller.cc
        controller/controller.h
        model/model.cc
        model/model.h
        model/object.cc
        model/object.h
        model/object_modify_strategy/modify.h
        model/object_modify_strategy/strategy_modify.h
        model/object_modify_strategy/object_centering.h
        model/object_modify_strategy/object_centering.cc
        model/object_modify_strategy/object_rotate.h
        model/object_modify_strategy/object_rotate.cc
        model/object_modify_strategy/object_scale.h
        model/object_modify_strategy/object_scale.cc
        model/object_modify_strategy/object_translation.h
        model/object_modify_strategy/object_translation.cc
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.10")
    qt_add_executable(3dViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(3dViewer SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(3dViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(3dViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(3dViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3dViewer)
endif()
