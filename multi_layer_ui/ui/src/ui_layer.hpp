#pragma once

#include <memory>
#include <engine/module_data.hpp>


namespace app
{
class ui_layer
{
public:
    explicit ui_layer(const std::shared_ptr<core::module_data>& data) : _data {data} { }
    virtual ~ui_layer() = default;
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void UpdateUI() = 0;

protected:
    std::shared_ptr<core::module_data> _data;
};

} // namespace app
