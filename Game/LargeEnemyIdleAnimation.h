#pragma once
#include "LinearAnimation.h"
class LargeEnemyIdleAnimation : public LinearAnimation 
{
	public:
		LargeEnemyIdleAnimation(sf::Sprite& sprite);
		bool init(const ContentManager& contentManager) override;
		const static float ANIMATION_LENGTH;

};

