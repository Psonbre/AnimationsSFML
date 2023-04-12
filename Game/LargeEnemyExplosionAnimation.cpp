#include "stdafx.h"
#include "LargeEnemyExplosionAnimation.h"
#include "ContentManager.h"

const float LargeEnemyExplosionAnimation::ANIMATION_LENGTH = 0.75;

LargeEnemyExplosionAnimation::LargeEnemyExplosionAnimation(sf::Sprite& sprite) : LinearAnimation(sprite, ANIMATION_LENGTH, false)
{
}

bool LargeEnemyExplosionAnimation::init(const ContentManager& contentManager)
{
	const sf::Texture& texture = contentManager.getLargeEnnemiesTexture();
	frames.push_back(AnimationFrame(texture, sf::IntRect(10, 313, 50, 50)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(68, 332, 20, 20)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(91, 328, 30, 30)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(119, 324, 35, 35)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(157, 324, 35, 35)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(195, 329, 25, 25)));
	return true;
}
