#pragma once

#include <thread>
#include <atomic>
#include <memory>
#include <engine/module_data.hpp>

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

namespace core
{
class API base_module
{
public:
    explicit base_module();
	virtual ~base_module();
    
    bool start();
    bool stop();

    std::shared_ptr<module_data> get_module_data()
    {
        return _module_data;
    }

protected:
    virtual void run() = 0;
    std::unique_ptr<std::thread> _thread;
    bool _is_running;

    std::shared_ptr<module_data> _module_data;
};
}