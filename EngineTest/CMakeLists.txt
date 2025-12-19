project(EngineTest)

file(GLOB_RECURSE MAIN_SOURCE "src/*.cpp")
if (NOT MAIN_SOURCE)
    file(GLOB MAIN_SOURCE "*.cpp")
endif()

add_executable(${PROJECT_NAME}
    ${MAIN_SOURCE}
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Work")