project(EngineLib)

file(GLOB_RECURSE LIB_SOURCES "src/*.cpp")
file(GLOB_RECURSE LIB_HEADERS "include/*.h")

if(NOT LIB_SOURCES)
    file(GLOB LIB_SOURCES "*.cpp")
endif()
if(NOT LIB_HEADERS)
    file(GLOB LIB_HEADERS "*.h")
endif()

add_library(${PROJECT_NAME}
STATIC
    ${LIB_HEADERS}
    ${LIB_SOURCES}
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Libraries")