#pragma once
#include "GameObject.h"

/// <summary>
/// Classe qui illustre de manière logique le vaisseau du joueur dans le jeu Asteroid
/// Pour le moment, on a que le déplacement du vaisseau.  Il peut pivoter et se déplacer
/// Par poussée avant.  Il garde toujours son inertie vectorielle.
/// </summary>
class PlayerShip : public GameObject
{
	static const float MAX_SPEED;
public:
	PlayerShip();
	/// <summary>
	/// Deplace le vaisseau dans l'espace
	/// On ajoute la nouvelle poussée à la poussée actuelle
	/// On limite la vitesse totale
	/// Puis on téléporte le vaisseau s'il arrive à un bout de l'écran.
	/// </summary>
	/// <param name="force">La poussée ajouté à ce frame.</param>
	/// <param name="rotation">La rotation ajouté à ce frame.</param>

	
	const sf::Vector2f& getVectorialThrust() const;
	bool update(float elapsedTime, float thrustValue, float rotationValue);
private:
	/// <summary>
	/// Limiter la poussée à la vitesse maximale
	/// </summary>
	void setMaximumThrust();
	void handleOutOfBoundsPosition();
	sf::Vector2f vectorialThrust;
	float shipThrust;
};


