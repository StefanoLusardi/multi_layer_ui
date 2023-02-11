#include "module_b.hpp"
#include <chrono>
#include <random>

namespace core
{
module_b::module_b()
{
}

module_b::~module_b()
{
}

void module_b::run()
{
    using namespace std::chrono_literals;
    
    std::random_device rd;
    std::mt19937 generator{ rd() }; 
    std::uniform_int_distribution<> distribution(-10, 10);
 
    auto random = [&]{ return distribution(generator); };

    int counter = 0;
    float offset = 200;

    auto& r = _module_data->rect_list.emplace_back(rect_t<float>{offset, offset, 150, 150});

    while(_is_running)
    {
        std::this_thread::sleep_for(300ms);
        
        r.x += random();
        r.y += random();

        _module_data->text = std::to_string(counter);
        counter++;
    }
}

}