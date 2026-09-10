#include "sessionCreator.hpp"
#include <CppEngine/helpers/equalityHelpers.hpp>
#include <CppEngine/imgui/imgui_stdlib.h>

using PlayerType = Player::PlayerType;
using AddPlayerPopup = SessionCreator::AddPlayerPopup;

AddPlayerPopup::AddPlayerPopup(std::vector<Player>& players):
    eng::PopupMenu("Add Player"),
    players(players),
    buffer(""),
    playerType(PlayerType::Human),
    difficulties{"Easy", "Medium", "Hard"},
    difficultySelection(0)
{
    renderMenu = [this]() { renderAddPlayerPopup(); };
}

void AddPlayerPopup::renderAddPlayerPopup()
{
    ImGui::InputText("Name: ", &buffer);

    if (ImGui::BeginCombo("Type: ", Player::playerTypeToString(playerType).c_str()))
    {
        for (int i = 0; i < 2; i++)
        {
            bool isSelected = i == (int)playerType || Player::playerTypeIsComp((PlayerType)i);

            if (ImGui::Selectable(Player::playerTypeToString((PlayerType)i).c_str(), isSelected))
            {
                playerType = (PlayerType)i;
            }

            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    if (Player::playerTypeIsComp(playerType) &&
        ImGui::BeginCombo("Computer Difficulty: ", difficulties[difficultySelection].c_str()))
    {
        for (int i = 0; i < 3; i++)
        {
            bool isSelected = i == difficultySelection;

            if (ImGui::Selectable(difficulties[i].c_str(), isSelected))
            {
                playerType = (PlayerType)(i + 1);
            }

            if (isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}

SessionCreator::SessionCreator(): addPlayerButton("Add Player"), addPlayerPopup(players)
{
    addPlayerButton.setOnPressed([this]() { onAddPlayer(); });
}

void SessionCreator::render()
{
    addPlayerButton.render();

    addPlayerPopup.render();
}

void SessionCreator::onAddPlayer()
{
    addPlayerPopup.open();
}
