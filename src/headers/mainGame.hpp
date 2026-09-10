#pragma once

#include <CppEngine/components/scene.hpp>

class MainGame: public eng::Scene
{
public:
    MainGame();

    void render() override;
};
