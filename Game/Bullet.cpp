#include "stdafx.h"
#include "Bullet.h"
#include "ContentManager.h"
#include "game.h"

const float Bullet::BULLET_SPEED = 600;
const unsigned long long Bullet::TIME_TO_LIVE = 2000;

Bullet::Bullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
  : GameObject()
{
  setPosition(initialPosition);
  move(initialThrust);
}

Bullet::Bullet(const Bullet& src)
  :GameObject(src)
{

}

bool Bullet::update(float elapsedTime)
{
  move(sf::Vector2f(BULLET_SPEED * elapsedTime, 0));
  if (getPosition().x > Game::GAME_WIDTH)
    return true;
  return false;
}

bool Bullet::init(const ContentManager& contentManager)
{
  GameObject::init(contentManager);
  setTexture(contentManager.getLargeEnnemiesTexture());
  setTextureRect(sf::IntRect(197, 67, 6, 6));
  return true;
}

