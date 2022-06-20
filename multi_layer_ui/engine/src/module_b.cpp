#include "module_b.hpp"
#include <chrono>

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
    
    while(_is_running)
    {
        std::this_thread::sleep_for(500ms);
        
    }
}

}