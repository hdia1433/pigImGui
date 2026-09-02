#include "mainMenu.hpp"
#include "sceneName.hpp"
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
    ImGui::PopFont();
    ImGui::PopStyleVar();
}

void MainMenu::onStart()
{
    eng::Globals::currentScene = SceneName::SessionCreator;
}

void MainMenu::onQuit()
{
    eng::Globals::running = false;
}
