set(TARGET_NAME ui)

add_library(${TARGET_NAME} STATIC
	include/ui/application.hpp
	src/application.cpp
	src/example_app.cpp
	src/example_app.hpp
	
	${CMAKE_SOURCE_DIR}/build/bindings/imgui_impl_glfw.cpp
	${CMAKE_SOURCE_DIR}/build/bindings/imgui_impl_glfw.h
	${CMAKE_SOURCE_DIR}/build/bindings/imgui_impl_opengl3.cpp
	${CMAKE_SOURCE_DIR}/build/bindings/imgui_impl_opengl3.h
)

find_package(imgui)
find_package(glfw3)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
target_include_directories(${TARGET_NAME} 
	PUBLIC include
	PRIVATE ${CMAKE_SOURCE_DIR}/build/bindings
)

target_link_libraries(${TARGET_NAME}
	PRIVATE imgui::imgui
	PRIVATE glfw
	PRIVATE engine
)