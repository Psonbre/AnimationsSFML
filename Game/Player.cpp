#include "stdafx.h"
#include "Player.h"
#include "Inputs.h"
#include "game.h"
#include "ContentManager.h"
#include "ShipAnimation.h"

Player::Player()
{

}

bool Player::init(const ContentManager& contentManager)
{
  activate();
  setPosition(sf::Vector2f(100.0f, Game::GAME_HEIGHT * 0.5f));
  currentState = State::SHIP;
  
  bool retval = addAnimation<State::SHIP, ShipAnimation>(contentManager);

  return retval && AnimatedGameObject::init(contentManager);
}

bool Player::update(float deltaT, const Inputs& inputs)
{
  move(sf::Vector2f(0, -inputs.moveFactor));
  return AnimatedGameObject::update(deltaT, inputs);
}

