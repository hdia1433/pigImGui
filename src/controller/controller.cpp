#include "controller.hpp"
#include "mainMenu.hpp"
#include "mainGame.hpp"
#include "sceneName.hpp"
#include "sessionCreator.hpp"

Controller::Controller():
    app({800, 800})
{
    eng::Globals::currentScene = "MainMenu";
#ifdef DEBUG
    eng::Resource::setRoot(eng::ProjectType::Debug);
#elifdef NDEBUG
    eng::Resources::setRoot(eng::ProjectType::app);
#endif

    app.addScene(SceneName::MainMenu, new MainMenu);
    app.addScene(SceneName::SessionCreator, new SessionCreator);
    app.addScene(SceneName::MainGame, new MainGame);
}

void Controller::start()
{
    app.render();
}
