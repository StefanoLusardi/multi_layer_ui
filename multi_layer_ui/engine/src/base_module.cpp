#include <engine/base_module.hpp>
#include <vector>

namespace core
{

base_module::base_module() : _is_running{ false } , _module_data { std::make_shared<module_data>() }
{
}

base_module::~base_module()
{
}

bool base_module::start()
{
    if (_is_running)
        return false;

    _is_running = true;
    _thread = std::make_unique<std::thread>([this]{ run(); });
    return true;
}

bool base_module::stop()
{
    if (!_is_running)
        return false;

    _is_running = false;
    if (_thread->joinable())
    {
        _thread->join();
        return true;
    }

    return false;
}


}