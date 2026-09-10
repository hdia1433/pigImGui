#pragma once

#include <CppEngine/components/scene.hpp>
#include <CppEngine/uiElement/button.hpp>
#include <CppEngine/uiElement/popupMenu.hpp>
#include "player.hpp"

class SessionCreator: public eng::Scene
{
public:
    class AddPlayerPopup: public eng::PopupMenu
    {
    private:
        std::vector<Player>& players;
        std::string buffer;
        Player::PlayerType playerType;
        std::string difficulties[3];
        int difficultySelection;

    public:
        AddPlayerPopup(std::vector<Player>& players);

    private:
        void renderAddPlayerPopup();
    };

private:
    eng::Button addPlayerButton;
    std::vector<Player> players;
    AddPlayerPopup addPlayerPopup;

public:
    SessionCreator();

    void render() override;

private:
    void onAddPlayer();
};
