#include "stdafx.h"
#include "Level01.h"
#include "game.h"

#include "ContentManager.h"

const float Level01::TIME_PER_FRAME = 1.0f / (float)Game::FRAME_RATE;
const float Level01::GAMEPAD_SPEEDRATIO = 1000.0f;
const float Level01::KEYBOARD_SPEED = 0.1f;
const float Level01::TIME_BETWEEN_FIRE = 0.5f;

Level01::Level01()
  : Scene(SceneType::LEVEL01)
{
}

Level01::~Level01()
{

}

SceneType Level01::update()
{
  static int cptScrollBackground = 0;
  backgroundSprite.setTextureRect(sf::IntRect((int)(0.5f * cptScrollBackground++), 0, Game::GAME_WIDTH, Game::GAME_HEIGHT));
  SceneType retval = getSceneType();
  player.update(1.0f / (float)Game::FRAME_RATE, inputs);
  for (LargeEnemy& e : enemies)
    if(e.update(1.0f/(float)Game::FRAME_RATE, inputs))
      e.deactivate();

  for (Bullet& e : bullets)
  {
    if(e.update(1.0f / (float)Game::FRAME_RATE))
      e.deactivate();
  }

  if (inputs.fireBullet && timeSinceLastFire >= TIME_BETWEEN_FIRE)
  {
    fireBullet(player.getPosition());
  }

  for (Bullet& b : bullets)
  {
    for (LargeEnemy& e : enemies)
    {
      if (b.collidesWith(e))
      {
        b.deactivate();
        e.onHit();
      }
    }
  }
  bullets.remove_if([](const GameObject& b){return !b.isActive();});
  enemies.remove_if([](const GameObject& b) {return !b.isActive(); });
  timeSinceLastFire+= 1.0f / (float)Game::FRAME_RATE;
  return retval;
}



void Level01::fireBullet(const sf::Vector2f& position)
{
  Bullet newBullet;
  newBullet.init(contentManager);
  newBullet.setPosition(position);
  newBullet.activate();
  bullets.push_back(newBullet);
  timeSinceLastFire = 0;
}
void Level01::draw(sf::RenderWindow& window) const
{
  window.draw(backgroundSprite);
  player.draw(window);
  for(const LargeEnemy& e: enemies)
    e.draw(window);
  for (const Bullet& e : bullets)
    e.draw(window);
}

bool Level01::uninit()
{
  return true;
}

bool Level01::init()
{
  timeSinceLastFire = TIME_BETWEEN_FIRE*3;
  inputs.reset();
  if (contentManager.loadContent() == false)
  {
    return false;
  }
  backgroundSprite.setTexture(contentManager.getBackgroundTexture());
  srand((unsigned)time(nullptr));

  for (int i = 0; i < 10; i++)
  {
    LargeEnemy enemy;
    enemy.init(contentManager);
    enemy.setPosition(sf::Vector2f((float)Game::GAME_WIDTH + 50.0f*(float)(rand()%100), i * (float)Game::GAME_HEIGHT / 10.0f));
    enemy.activate();
    enemies.push_back(enemy);
  }
  
  return player.init(contentManager);
}
bool Level01::handleEvents(sf::RenderWindow& window)
{
  bool retval = false;
  inputs.reset();
  sf::Event event;
  while (window.pollEvent(event))
  {
    //x sur la fen�tre
    if (event.type == sf::Event::Closed)
    {
      window.close();
      retval = true;
    }
  }
  inputs.moveFactor += sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ? 3.0f : 0.0f;
  inputs.moveFactor += sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ? -3.0f : 0.0f;
  inputs.fireBullet = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

  return retval;
}
