#pragma once
#include "scenetype.h"
class Scene
{
public:
  Scene(SceneType type);
  virtual ~Scene();
  virtual SceneType update() = 0;
  virtual void draw(sf::RenderWindow& window) const = 0;
  virtual void pause();
  virtual void unPause();
  virtual bool init() = 0;
  virtual bool uninit() = 0;
  virtual bool handleEvents(sf::RenderWindow& window);
  SceneType getSceneType() const;
private:
  SceneType sceneType;
};

