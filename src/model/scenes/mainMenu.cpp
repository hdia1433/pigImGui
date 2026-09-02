#include "mainMenu.hpp"
#include <CppEngine/imgui-SFML.h>

MainMenu::MainMenu():
    pigLogo(eng::Resource::getResourcePath("images/PigLogo.png")),
    buttonFont(ImGui::GetIO().Fonts->AddFontFromFileTTF(eng::Resource::getResourcePath("fonts/TATTI___.TTF").c_str(), 40)),
    startButton("Start", {200, 50}),
    quitButton("Quit", {200, 50})
{
    if(!ImGui::SFML::UpdateFontTexture())
    {
        throw std::runtime_error("Unabled to update font texture.");
    }

    startButton.setOnPressed(&MainMenu::onStart);
    startButton.setAlignment(eng::UIElement::Alignment::Centre);
    quitButton.setOnPressed(&MainMenu::onQuit);
    quitButton.setAlignment(eng::UIElement::Alignment::Centre);
}

void MainMenu::render()
{
    float logoWidth = ImGui::GetWindowSize().x / 2;
    const sf::Vector2u logoSize = pigLogo.getSize();
    float logoHeight = logoWidth * (float)logoSize.y / logoSize.x;

    ImGui::SetCursorPos({ImGui::GetWindowSize().x / 4, ImGui::GetWindowSize().y / 8});
    ImGui::PushStyleVarY(ImGuiStyleVar_ItemSpacing, ImGui::GetWindowSize().y / 8);

    ImGui::Image(pigLogo, sf::Vector2f(logoWidth, logoHeight));

    ImGui::PushFont(buttonFont);
    startButton.render();
    quitButton.render();
    // ImVec2 buttonSize(200 * eng::Globals::scale, 50 * eng::Globals::scale);
    // ImGui::SetCursorPosX((ImGui::GetWindowSize().x - buttonSize.x) / 2);
    // if(ImGui::Button("Start", buttonSize))
    // {
    //
    // }
    //
    // ImGui::SetCursorPosX((ImGui::GetWindowSize().x - buttonSize.x) / 2);
    // if(ImGui::Button("Quit", buttonSize))
    // {
    //     eng::Globals::running = false;
    // }
    ImGui::PopFont();
    ImGui::PopStyleVar();
}

void MainMenu::onStart()
{

}

void MainMenu::onQuit()
{
    eng::Globals::running = false;
}
