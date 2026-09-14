#pragma once

#include <CppEngine/backend/controller.hpp>
#include <CppEngine/backend/globals.hpp>

class Controller
{
private:
    eng::Controller app;

public:
    Controller();

    void start();
};
