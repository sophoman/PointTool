cmake_minimum_required(VERSION 3.16)

project(Point VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS AxContainer)


set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Point
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        datamanager.h datamanager.cpp
        exportthreadmanager.h exportthreadmanager.cpp
        progressmanager.h progressmanager.cpp
        res.qrc
        clickablelabel.h clickablelabel.cpp
        configmanager.h configmanager.cpp
        devicebase.h devicebase.cpp
        pumpdevice.h pumpdevice.cpp
        excelmanager.h excelmanager.cpp

        widget.ui
        attach.h attach.cpp attach.ui
        fourvalvedevice.h fourvalvedevice.cpp
        textinput.h textinput.cpp textinput.ui
        blockdevice.h blockdevice.cpp
        editablecombobox.h editablecombobox.cpp
        editabletextedit.h editabletextedit.cpp
        vivalvedevice.h vivalvedevice.cpp
        vxvalvedevice.h vxvalvedevice.cpp
        singlevalvedevice.h singlevalvedevice.cpp
        jsonmanager.h jsonmanager.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Point APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Point SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Point
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Point PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Point PRIVATE Qt${QT_VERSION_MAJOR}::AxContainer)

#提升为自定义控件是需要添加
target_include_directories(Point PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(Point PRIVATE clickablelabel.h clickablelabel.cpp)
target_sources(Point PRIVATE editablecombobox.h editablecombobox.cpp)
target_sources(Point PRIVATE editabletextedit.h editabletextedit.cpp)
#exe图标
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/Image/Point.rc")
target_sources(Point PRIVATE ${APP_ICON_RESOURCE_WINDOWS})
#Quazip

set(QUAZIP_DIR "${CMAKE_SOURCE_DIR}/bin/quazip")

add_library(QuaZip SHARED IMPORTED)
set_target_properties(QuaZip PROPERTIES
    IMPORTED_IMPLIB "${QUAZIP_DIR}/dll/libquazip1-qt6.dll.a"
    IMPORTED_LOCATION "${QUAZIP_DIR}/dll/libquazip1-qt6.dll"
    INTERFACE_INCLUDE_DIRECTORIES "${QUAZIP_DIR}/include"
)

add_custom_command(TARGET Point POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${QUAZIP_DIR}/dll/libquazip1-qt6.dll"
        $<TARGET_FILE_DIR:Point>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${QUAZIP_DIR}/dll/zlib1.dll"
        $<TARGET_FILE_DIR:Point>
)

target_link_libraries(Point PRIVATE QuaZip)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Point)
endif()
set_target_properties(Point PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Point
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Point)
endif()
