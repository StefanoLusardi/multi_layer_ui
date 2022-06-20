#include "module_a.hpp"
#include "engine/module_data.hpp"
#include "engine/rect_t.hpp"
#include <chrono>
#include <memory>
#include <string>

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

    int counter = 0;
    float offset = 50;
    _module_data->rect_list.push_back(rect_t<float>{offset, offset, 100, 100});

    while(_is_running)
    {
        std::this_thread::sleep_for(500ms);
        
        if (counter > 9)
        {
            counter = 0;
            _module_data->rect_list[0].x = offset;
            _module_data->rect_list[0].y = offset;
        }

        _module_data->rect_list[0].x += offset;
        _module_data->rect_list[0].y += offset;
        _module_data->text = std::to_string(counter);

        counter++;
    }
}

}