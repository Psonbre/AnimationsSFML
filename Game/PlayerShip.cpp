#include "stdafx.h"
#include "PlayerShip.h"
#include <cmath>
#include "game.h"


const float PlayerShip::MAX_SPEED = 15.0f;

PlayerShip::PlayerShip()
{
	vectorialThrust.x = vectorialThrust.y = 0.0f;
	activate();
}

const sf::Vector2f& PlayerShip::getVectorialThrust() const
{
	return vectorialThrust;
}


bool PlayerShip::update(float elapsedTime, float thrustValue, float rotationValue)
{
	shipThrust = fabs(thrustValue);

	//Rotation du vaisseau
	rotateInRadians(rotationValue);

	//Angle 0 est un vecteur qui pointe vers la droite, et on augmente l'angle dans le sens des aiguilles d'une montre
	vectorialThrust += sf::Vector2f(cos(getRotationAngleInRadians()), sin(getRotationAngleInRadians())) * shipThrust;

	//On ajoute la poussee à la position
	move(vectorialThrust);

	//Dans bien des vieux jeux la vitesse maximum semble être par axe, mais comme on a de la puissance de calcul
	//on va la faire sur le déplacement total, peu importe l'angle.
	setMaximumThrust();

	//Déplacement potentil de l'autre côté.  On se donne un buffer de la taille de notre objet
	handleOutOfBoundsPosition();
	return false;
}

void PlayerShip::handleOutOfBoundsPosition()
{
	sf::Vector2f newPosition = getPosition();
	if (newPosition.x > Game::GAME_WIDTH + getGlobalBounds().width / 2.0f)
	{
		newPosition.x -= Game::GAME_WIDTH + getGlobalBounds().width ;
	}
	else if (newPosition.x < -getGlobalBounds().width *0.5f)
	{
		newPosition.x += Game::GAME_WIDTH + getGlobalBounds().width ;
	}

	if (newPosition.y > Game::GAME_HEIGHT + getGlobalBounds().height / 2.0f)
	{
		newPosition.y -= Game::GAME_HEIGHT + getGlobalBounds().height ;
	}
	else if (newPosition.y < -getGlobalBounds().height * 0.5f)
	{
		newPosition.y += Game::GAME_HEIGHT + getGlobalBounds().height ;
	}

	GameObject::setPosition(newPosition);
}


void PlayerShip::setMaximumThrust()
{
	//Calcul de la vitesse maximum actuelle (pythagore)
	float vitesseTotale = sqrt(vectorialThrust.x * vectorialThrust.x + vectorialThrust.y * vectorialThrust.y);

	//Si plus grande que la vitesse actuelle, on se fait un ratio
	if (vitesseTotale > MAX_SPEED)
	{
		vectorialThrust *= MAX_SPEED / vitesseTotale;
	}
}

