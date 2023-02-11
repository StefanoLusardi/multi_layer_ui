set(TARGET_NAME engine)
add_library(${TARGET_NAME} STATIC
	include/engine/engine.hpp
	include/engine/base_module.hpp
	include/engine/module_data.hpp
	include/engine/rect_t.hpp
	
	src/base_module.cpp
	src/engine.cpp
	src/module_a.cpp
	src/module_a.hpp
	src/module_b.cpp
	src/module_b.hpp
)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
target_include_directories(${TARGET_NAME} PUBLIC include)
