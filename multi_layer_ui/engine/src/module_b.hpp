#pragma once

#include <engine/base_module.hpp>

namespace core
{
class module_b : public base_module
{
public:
    explicit module_b();
    ~module_b();

    void run() override;
    
private:
};

}