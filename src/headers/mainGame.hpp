#pragma once

#include <CppEngine/scene.hpp>

class MainGame: public eng::Scene
{
public:
    MainGame();

    void render() override;
};
