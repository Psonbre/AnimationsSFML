#pragma once
#include "GameObject.h"
#include "AnimatedGameObject.h"
struct Inputs;
class Player :
    public AnimatedGameObject
{
 public:
  Player();
   virtual bool init(const ContentManager& contentManager) override;
   
   bool update(float deltaT, const Inputs& inputs) override;
};

