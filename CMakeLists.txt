cmake_minimum_required(VERSION "3.26")

project(HMVS)

FILE(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS FOLLOW_SYMLINKS main.cpp src/*.cpp)

set(TARGET_NAME HMVS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/release)

set(QT6_DIR C:/Qt/6.5.1/mingw_64)
set(QT_COMPONENTS Widgets)

set(CMAKE_PREFIX_PATH ${QT6_DIR})
find_package(Qt6 REQUIRED COMPONENTS ${QT_COMPONENTS})
include_directories(${QT6_DIR}/include)

qt_standard_project_setup()
set(CMAKE_AUTORCC ON)

qt_add_executable(${TARGET_NAME} ${SOURCES} )
foreach(LIB ${QT_COMPONENTS})
    target_link_libraries(${TARGET_NAME} PRIVATE Qt6::${LIB})
endforeach()

set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE ON)
set(BUILD_DIR ${PROJECT_SOURCE_DIR}/build)
set(DIST_DIR ${BUILD_DIR}/dist)
set(CMAKE_INSTALL_PREFIX ${DIST_DIR})

install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
qt_generate_deploy_app_script(
    TARGET ${TARGET_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
