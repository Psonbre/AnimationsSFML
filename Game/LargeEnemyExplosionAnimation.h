#pragma once
#include "LinearAnimation.h"
class LargeEnemyExplosionAnimation : public LinearAnimation
{
	public:
		LargeEnemyExplosionAnimation(sf::Sprite& sprite);
		bool init(const ContentManager& contentManager) override;
		const static float ANIMATION_LENGTH;
};

