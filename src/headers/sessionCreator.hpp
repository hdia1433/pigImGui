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
        SessionCreator& sessionCreator;
        std::string buffer;
        Player::PlayerType playerType;
        std::vector<std::string> difficulties;
        int difficultySelection;
    public:
        AddPlayerPopup(SessionCreator& sessionCreator);

        void render() override;
    };
private:
    eng::Button addPlayerButton;
    AddPlayerPopup addPlayerPopup;
    std::vector<Player> players;

public:
    SessionCreator();

    void render() override;

    void addPlayer(const Player& player);

private:
    void onAddPlayer();
};
