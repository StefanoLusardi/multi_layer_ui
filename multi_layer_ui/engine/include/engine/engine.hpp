#pragma once

#include <engine/base_module.hpp>
#include <map>
#include <thread>
#include <memory>
#include <string>

namespace core
{
class engine
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
