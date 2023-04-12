#include "stdafx.h"
#include "LargeEnemy.h"
#include "Inputs.h"
#include "game.h"
#include "ContentManager.h"
#include "AnimatedGameObject.h"
#include "LargeEnemyExplosionAnimation.h"
#include "LargeEnemyIdleAnimation.h"

LargeEnemy::LargeEnemy()
  :isDead(false)
{

}
LargeEnemy::LargeEnemy(const LargeEnemy& src)
  : AnimatedGameObject(src)
  , isDead(src.isDead)
{
  init(*contentManager);

  setPosition(src.getPosition());
  if (src.isActive())
    activate();
  else
    deactivate();
}
bool LargeEnemy::init(const ContentManager& contentManager)
{
  isDead = false;
  setPosition(sf::Vector2f(0.0f, Game::GAME_HEIGHT * 0.5f));
  currentState = State::IDLE;

  bool retval = addAnimation<State::IDLE, LargeEnemyIdleAnimation>(contentManager);
  retval = addAnimation<State::EXPLODING, LargeEnemyExplosionAnimation>(contentManager) && retval;

  return retval && AnimatedGameObject::init(contentManager);
} 

bool LargeEnemy::update(float deltaT, const Inputs& inputs)
{
  if (animations[currentState]->isOver() && isDead)
    return true;
  move(sf::Vector2f(-5, 0));
  if (getGlobalBounds().left < -getGlobalBounds().width * 0.5f && currentState != State::EXPLODING)
    setPosition(sf::Vector2f((float)Game::GAME_WIDTH, getPosition().y));

  return AnimatedGameObject::update(deltaT, inputs);
}

void LargeEnemy::onHit()
{
  currentState = State::EXPLODING;
  isDead = true;
}