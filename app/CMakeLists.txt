cmake_minimum_required(VERSION 3.16)

project(SoundMixerApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(SoundMixerApp
    main.cpp
    SoundTrackListModel.cpp
    SoundTrackListModel.hpp
    SoundTrack.cpp
    SoundTrack.hpp
    Controller.cpp
    Controller.hpp
)

qt_add_qml_module(SoundMixerApp
    URI app
    VERSION 1.0
    QML_FILES
        qml/main.qml
        qml/SoundList.qml
        qml/SoundTrack.qml

    RESOURCES
        images/delete.svg
        images/merge.svg
)

set_target_properties(SoundMixerApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(SoundMixerApp
    PRIVATE Qt6::Quick SoundMixerLib)
