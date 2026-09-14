#pragma once

#include <CppEngine/parents/scene.hpp>

class MainGame: public eng::Scene
{
public:
    MainGame();

    void render() override;
};
