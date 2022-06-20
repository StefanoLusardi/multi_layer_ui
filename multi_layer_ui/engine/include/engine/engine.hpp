#pragma once

#include <engine/base_module.hpp>
#include <map>
#include <thread>
#include <memory>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif


namespace core
{
class API engine
{
public:
	explicit engine();
	~engine();
	
	void start();
	void stop();

	std::map<std::string, std::unique_ptr<base_module>> _modules;

private:
};

}
