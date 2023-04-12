#pragma once
class ContentManager
{
public:
	ContentManager();
	virtual bool loadContent();

	const sf::Texture& getBackgroundTexture() const;
	const sf::Texture& getLargeEnnemiesTexture() const;
	const sf::Texture& getShipAnimationTexture() const;
private:
	sf::Texture largeEnnemiesTexture;
	sf::Texture backgroundTexture;
	sf::Texture shipAnimationTexture;
};



