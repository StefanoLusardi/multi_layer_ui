#include "module_a.hpp"
#include "engine/module_data.hpp"
#include "engine/rect_t.hpp"
#include <chrono>
#include <memory>
#include <string>
#include <random>

namespace core
{
module_a::module_a()
{
}

module_a::~module_a()
{
}

void module_a::run()
{
    using namespace std::chrono_literals;

    std::random_device rd;
    std::mt19937 generator{ rd() }; 
    std::uniform_int_distribution<> distribution(-10, 10);
 
    auto random = [&]{ return distribution(generator); };

    int counter = 0;
    float offset = 300;

    _module_data->rect_list.emplace_back(rect_t<float>{offset, offset, 100, 100});
    _module_data->rect_list.emplace_back(rect_t<float>{offset, offset, 200, 200});
    _module_data->rect_list.emplace_back(rect_t<float>{offset, offset, 50, 50});

    while(_is_running)
    {
        std::this_thread::sleep_for(500ms);
        
        for (auto&& rect : _module_data->rect_list)
        {
            rect.x += random();
            rect.y += random();
        }

        _module_data->text = std::to_string(counter);
        counter++;
    }
}

}