#include "sessionCreator.hpp"
#include <CppEngine/imgui/imgui_stdlib.h>
#include <CppEngine/helpers/equalityHelpers.hpp>

using PlayerType = Player::PlayerType;

SessionCreator::AddPlayerPopup::AddPlayerPopup(SessionCreator& sessionCreator):
    eng::PopupMenu(true),
    sessionCreator(sessionCreator),
    buffer(""),
    playerType(Player::PlayerType::Human),
    difficulties(
            {
                "Easy",
                "Medium",
                "Hard"
            }),
    difficultySelection(0)
{}

void SessionCreator::AddPlayerPopup::render()
{

    if(ImGui::Begin("Add Player"))
    {
        ImGui::InputText("Name: ", &buffer);

        if(ImGui::BeginCombo("Type: ", Player::playerTypeToString(playerType).c_str()))
        {
            for(int i = 0; i < 2; i++)
            {
                bool isSelected = i == (int)playerType || Player::playerTypeIsComp((PlayerType)i);

                if(ImGui::Selectable(Player::playerTypeToString((PlayerType)i).c_str()), isSelected)
                {
                    playerType = (PlayerType)i;
                }

                if(isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        if(Player::playerTypeIsComp(playerType) && ImGui::BeginCombo("Computer Difficulty: ", difficulties[difficultySelection].c_str()))
        {
            for(int i = 0; i < 3; i++)
            {
                bool isSelected = i == difficultySelection;

                if(ImGui::Selectable(difficulties[i].c_str(), isSelected))
                {
                    playerType = (PlayerType)(i + 1);
                }

                if(isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }
    }
    ImGui::End();
}

SessionCreator::SessionCreator():
    addPlayerButton("Add Player"),
    addPlayerPopup(*this)
{
    addPlayerButton.setOnPressed([this]()
            {
                onAddPlayer();
            });
}

void SessionCreator::render()
{
    addPlayerButton.render();

    if(addPlayerPopup.getVisible())
    {
        addPlayerPopup.render();
    }
}

void SessionCreator::addPlayer(const Player& player)
{
    players.emplace_back(player);
}

void SessionCreator::onAddPlayer()
{
    addPlayerPopup.setVisible(true);
}
