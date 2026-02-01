project(EngineTest)

file(GLOB_RECURSE MAIN_SOURCE "src/*.cpp")
file(GLOB_RECURSE MAIN_INCLUDE "include/*.h")

if (NOT MAIN_SOURCE)
    file(GLOB MAIN_SOURCE "*.cpp")
endif()
if (NOT MAIN_INCLUDE)
    file(GLOB MAIN_INCLUDE "*.h")
endif()

add_executable(${PROJECT_NAME}
    ${MAIN_SOURCE}
    ${MAIN_INCLUDE}
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE EngineLib)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Work")