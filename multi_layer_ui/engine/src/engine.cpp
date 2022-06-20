#include <engine/engine.hpp>

#include "module_a.hpp"
#include "module_b.hpp"

using namespace std::chrono_literals;

namespace core
{
engine::engine()
{
    _modules.emplace("module_a", std::make_unique<core::module_a>());
    _modules.emplace("module_b", std::make_unique<core::module_b>());
}

engine::~engine()
{
}

void engine::start()
{
    for (auto&&[_, m] : _modules)
        m->start();
}

void engine::stop()
{
    for (auto&&[_, m] : _modules)
        m->stop();
}

}
