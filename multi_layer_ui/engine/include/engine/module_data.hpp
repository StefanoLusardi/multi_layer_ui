#pragma once

#include <engine/rect_t.hpp>
#include <vector>
#include <memory>
#include <string>

#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

namespace core
{
struct API module_data
{
    std::vector<rect_t<float>> rect_list;
	std::string text;
};

}