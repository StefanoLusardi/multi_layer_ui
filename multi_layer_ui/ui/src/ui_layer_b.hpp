#pragma once

#include "ui_layer.hpp"
#include <imgui.h>

namespace app
{
class ui_layer_b : public ui_layer
{
public:
    explicit ui_layer_b(const std::shared_ptr<core::module_data>& data) : ui_layer(data) {}
    ~ui_layer_b() = default;

    void UpdateUI() override
    {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        const ImU32 color = ImColor(0, 255, 0);

        for (auto&& rect : _data->rect_list)
        {
            auto x = rect.x;
            auto y = rect.y;
            auto w = rect.w;
            auto h = rect.h;

            draw_list->AddRect(ImVec2(x, y), ImVec2(x+w, y+h), color);
            draw_list->AddText(ImVec2(x + w*0.5f, y + h*0.5f), color, _data->text.c_str());
        }
    }
};

} // namespace app
