#include "player.hpp"
#include <CppEngine/helpers/equalityHelpers.hpp>

Player::Player(std::string_view name, PlayerType type):
    name(name),
    type(type)
{

}

std::string Player::playerTypeToString(PlayerType type)
{
    switch(type)
    {
        case PlayerType::Human:
            return "Human";
        default:
            return "Computer";
    }
}

bool Player::playerTypeIsComp(PlayerType type)
{
    return eng::equalsOr(type, {PlayerType::EasyComp, PlayerType::MedComp, PlayerType::HardComp});
}
