#pragma once
#include "GameObject.h"
#include "AnimatedGameObject.h"
class LargeEnemy :
  public AnimatedGameObject
{
public:
  LargeEnemy();
  LargeEnemy(const LargeEnemy& src);
  virtual bool init(const ContentManager& contentManager) override;
  bool update(float deltaT, const Inputs& inputs) override;
  void onHit();
private:
  bool isDead;
};

