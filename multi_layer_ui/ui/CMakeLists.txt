set(TARGET_NAME ui)

add_library(${TARGET_NAME} STATIC
	include/ui/application.hpp
	src/application.cpp
	src/example_app.cpp
	src/example_app.hpp
	
	${CMAKE_BINARY_DIR}/bindings/imgui_impl_glfw.cpp
	${CMAKE_BINARY_DIR}/bindings/imgui_impl_glfw.h
	${CMAKE_BINARY_DIR}/bindings/imgui_impl_opengl3.cpp
	${CMAKE_BINARY_DIR}/bindings/imgui_impl_opengl3.h
)

find_package(imgui)
find_package(glfw3)
#find_package(Poco)

target_include_directories(${TARGET_NAME} 
	PUBLIC include
	PRIVATE ${CMAKE_BINARY_DIR}/bindings
)

target_link_libraries(${TARGET_NAME}
	PRIVATE imgui::imgui
	PRIVATE glfw
	#PRIVATE Poco::Poco
	PRIVATE engine
)