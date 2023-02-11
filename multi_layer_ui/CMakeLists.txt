add_subdirectory(engine)
add_subdirectory(ui)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ui)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
