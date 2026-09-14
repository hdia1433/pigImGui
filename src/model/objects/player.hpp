#pragma once

class Player
{
public:
    enum class PlayerType
    {
        Human,
        EasyComp,
        MedComp,
        HardComp
    };
private:
    std::string name;
    PlayerType type;
public:
    Player(std::string_view name, PlayerType type);

    static std::string playerTypeToString(PlayerType type);
    static bool playerTypeIsComp(PlayerType type);
};
