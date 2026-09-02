#pragma once

#include <CppEngine/scene.hpp>

class SessionCreator: public eng::Scene
{
public:
    SessionCreator();

    void render() override;
};
