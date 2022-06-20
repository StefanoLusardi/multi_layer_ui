#pragma once

#include <engine/base_module.hpp>
#include <engine/rect_t.hpp>

namespace core
{
class module_a : public base_module
{
public:
    explicit module_a();
    ~module_a();

    void run() override;
};

}