#include "stdafx.h"
#include "ContentManager.h"


ContentManager::ContentManager()
{
}

bool ContentManager::loadContent()
{

  if (!backgroundTexture.loadFromFile("Assets\\Sprites\\SpaceBackground.jpg"))
    return false;
  else
    // ppoulin
    // Exercice07
    backgroundTexture.setRepeated(true);
  if(!largeEnnemiesTexture.loadFromFile("Assets\\Sprites\\NESGradiusLargeEnemies.bmp"))
    return false;
  if (!shipAnimationTexture.loadFromFile("Assets\\Sprites\\Ship.png"))
    return false;
  return true;
} 

const sf::Texture& ContentManager::getBackgroundTexture() const
{
  return backgroundTexture;
}
const sf::Texture& ContentManager::getShipAnimationTexture() const
{
  return shipAnimationTexture;
}

const sf::Texture& ContentManager::getLargeEnnemiesTexture() const
{
  return largeEnnemiesTexture;
}