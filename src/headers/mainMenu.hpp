#pragma once

#include <CppEngine/components/scene.hpp>
#include <CppEngine/uiElement/button.hpp>

class MainMenu: public eng::Scene
{
private:
    sf::Texture pigLogo;
    ImFont* buttonFont;
    eng::Button startButton;
    eng::Button quitButton;

public:
    MainMenu();

    void render() override;

private:
    static void onStart();
    static void onQuit();
};
