#pragma once

#include <engine/rect_t.hpp>
#include <vector>
#include <memory>
#include <string>

namespace core
{
struct module_data
{
    std::vector<rect_t<float>> rect_list;
	std::string text;
};

}