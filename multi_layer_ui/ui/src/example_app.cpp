#include "example_app.hpp"
#include <engine/engine.hpp>
#include <imgui.h>
#include <memory>
#include "engine/module_data.hpp"
#include "ui_layer_a.hpp"
#include "ui_layer_b.hpp"

namespace app
{
std::unique_ptr<Application> create_application()
{
    return std::make_unique<ExampleApp>();
}

ExampleApp::~ExampleApp()
{
    for (auto&& layer : _ui_layers)
        layer.second->OnDetach();

    _ui_layers.clear();
}

void ExampleApp::OnInit()
{
    _engine = std::make_unique<core::engine>();

    auto module_data_a = _engine->_modules["module_a"]->get_module_data();
    auto module_data_b = _engine->_modules["module_b"]->get_module_data();

    AddUiLayer("module_a", std::make_shared<ui_layer_a>(module_data_a));
    AddUiLayer("module_b", std::make_shared<ui_layer_b>(module_data_b));

    // ImGuiStyle* style = &ImGui::GetStyle();
    // style->Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);

    _engine->start();
}

void ExampleApp::OnShutdown()
{
    _engine->stop();
}

bool ExampleApp::AddUiLayer(const std::string& layer_name, const std::shared_ptr<ui_layer>& layer) 
{
    if (auto layer_iterator = _ui_layers.find(layer_name); layer_iterator == _ui_layers.end())
    {
        _ui_layers.emplace(layer_name, layer);
        layer->OnAttach();
        return true;
    }

    return false;
}

bool ExampleApp::RemoveUiLayer(const std::string& layer_name)
{
    if (auto layer_iterator = _ui_layers.find(layer_name); layer_iterator != _ui_layers.end())
    {
        layer_iterator->second->OnDetach();
        _ui_layers.erase(layer_name);
        return true;
    }

    return false;
}

void ExampleApp::UpdateUi()
{
    // ImGui::ShowDemoWindow();
    // return;

    {
        static ImGuiWindowFlags main_window_flags = 
            ImGuiWindowFlags_NoDecoration | 
            ImGuiWindowFlags_NoMove | 
            ImGuiWindowFlags_NoSavedSettings | 
            ImGuiWindowFlags_NoTitleBar | 
            ImGuiWindowFlags_NoCollapse;
        
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);

        ImGui::Begin("MainWindow", NULL, main_window_flags);

        for (auto&& [layer_name, layer] : _ui_layers)
            layer->UpdateUI();

        ImGui::End();
    }
}

} // namespace app
