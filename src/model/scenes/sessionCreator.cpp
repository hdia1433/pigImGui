#include "sessionCreator.hpp"

void SessionCreator::AddPlayerPopup::render()
{
    
}

SessionCreator::SessionCreator():
    addPlayerButton("Add Player")
{
    addPlayerButton.setOnPressed(&SessionCreator::onAddPlayer);
}

void SessionCreator::render()
{
    addPlayerButton.render();
}

void SessionCreator::onAddPlayer()
{
    
}
