#include "stdafx.h"
#include "LargeEnemyIdleAnimation.h"
#include "LinearAnimation.h"
#include "ContentManager.h"

const float LargeEnemyIdleAnimation::ANIMATION_LENGTH = 1;

LargeEnemyIdleAnimation::LargeEnemyIdleAnimation(sf::Sprite& sprite) : LinearAnimation(sprite, ANIMATION_LENGTH, false)
{
}

bool LargeEnemyIdleAnimation::init(const ContentManager& contentManager)
{
	const sf::Texture& texture = contentManager.getLargeEnnemiesTexture();
	frames.push_back(AnimationFrame(texture, sf::IntRect(10, 43, 50, 50)));
	return true;
}
