project(lib)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    ${SOURCE_DIR}/Collision.cpp
    ${SOURCE_DIR}/Component.cpp
    ${SOURCE_DIR}/Composite.cpp
    ${SOURCE_DIR}/Factory.cpp
    ${SOURCE_DIR}/GameObject.cpp
    ${SOURCE_DIR}/PathManager.cpp
    ${SOURCE_DIR}/SceneManager.cpp
    ${SOURCE_DIR}/TextureManager.cpp
    ${SOURCE_DIR}/Maths.cpp
)

set(HEADERS
    ${HEADER_DIR}/Collision.h
    ${HEADER_DIR}/Component.h
    ${HEADER_DIR}/Composite.h
    ${HEADER_DIR}/Factory.h
    ${HEADER_DIR}/GameObject.h
    ${HEADER_DIR}/PathManager.h
    ${HEADER_DIR}/SceneManager.h
    ${HEADER_DIR}/TextureManager.h
    ${HEADER_DIR}/Maths.h
)

add_library(${PROJECT_NAME}
STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${HEADER_DIR}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Libraries")