#include "controller.hpp"
#include "mainMenu.hpp"

Controller::Controller():
    app({800, 800})
{
    eng::Globals::currentScene = "MainMenu";
#ifdef DEBUG
    eng::Resource::setRoot(eng::ProjectType::Debug);
#elifdef NDEBUG
    eng::Resources::setRoot(eng::ProjectType::app);
#endif

    app.addScene("MainMenu", new MainMenu);
}

void Controller::start()
{
    app.render();
}
