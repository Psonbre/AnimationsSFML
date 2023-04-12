#include "stdafx.h"
#include <iostream>
#include "InputBasedAnimation.h"
#include "ShipAnimation.h"
#include "ContentManager.h"
#include "Inputs.h"
#include <algorithm>


ShipAnimation::ShipAnimation(sf::Sprite& sprite) : InputBasedAnimation(sprite), nbFrameInState(24)
{

}

bool ShipAnimation::init(const ContentManager& contentManager)
{
	const sf::Texture& texture = contentManager.getShipAnimationTexture();
	frames.push_back(AnimationFrame(texture, sf::IntRect(0, 0, 70, 32)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(70, 0, 70, 32)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(140, 0, 70, 32)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(210, 0, 70, 32)));
	frames.push_back(AnimationFrame(texture, sf::IntRect(280, 0, 70, 32)));
	return true;
}

void ShipAnimation::adjustNextFrame(const Inputs& inputs)
{
	if (inputs.moveFactor < 0) nbFrameInState = std::min(nbFrameInState + 1, 49);
	else if (inputs.moveFactor > 0) nbFrameInState = std::max(nbFrameInState - 1, 0);
	else nbFrameInState += (nbFrameInState < 24) ? 1 : -1;
	nextFrame = (unsigned int) std::min(std::floor((float)nbFrameInState / 10), 4.0f);
}
