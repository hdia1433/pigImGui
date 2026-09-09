#pragma once

#include <CppEngine/scene.hpp>
#include <CppEngine/button.hpp>
#include <CppEngine/popupMenu.hpp>

class SessionCreator: public eng::Scene
{
public:
    class AddPlayerPopup: public eng::PopupMenu
    {
    public:
        void render() override;
    };
private:
    eng::Button addPlayerButton;
public:
    SessionCreator();

    void render() override;

private:
    static void onAddPlayer();
};
