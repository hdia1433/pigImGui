#pragma once

#include <CppEngine/controller.hpp>
#include <CppEngine/globals.hpp>

class Controller
{
private:
    eng::Controller app;

public:
    Controller();

    void start();
};
