cmake_minimum_required(VERSION 3.5)

project(UdsDiagnosticTool VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Concurrent SerialBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Concurrent SerialBus)
find_file(PCAN_LIB PCANBasic.dll PATHS lib)
find_file(PCAN_UDS_LIB PCAN-UDS.dll PATHS lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/services)

file(GLOB cmd
    "src/*"
    "src/services/*"
    "src/services/include/*"
    "src/connection/*"
    "src/connection/include/*"
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        icons.qrc
        connectcandialog.ui
        sequence.cpp
        sequence.h
        servicemodel.cpp
        servicemodel.h
        types.h
        resultmodel.cpp
        resultmodel.h
        uds_api.cpp
        uds_api.h
        result.cpp
        result.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UdsDiagnosticTool
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET UdsDiagnosticTool APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(UdsDiagnosticTool SHARED
            ${PROJECT_SOURCES} ${cmd}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(UdsDiagnosticTool
            ${PROJECT_SOURCES} ${cmd}
        )
    endif()
endif()

target_link_libraries(UdsDiagnosticTool PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Concurrent Qt${QT_VERSION_MAJOR}::SerialBus ${PCAN_LIB} ${PCAN_UDS_LIB})

set_target_properties(UdsDiagnosticTool PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS UdsDiagnosticTool
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UdsDiagnosticTool)
endif()
