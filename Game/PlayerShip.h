#pragma once
#include "GameObject.h"

/// <summary>
/// Classe qui illustre de mani�re logique le vaisseau du joueur dans le jeu Asteroid
/// Pour le moment, on a que le d�placement du vaisseau.  Il peut pivoter et se d�placer
/// Par pouss�e avant.  Il garde toujours son inertie vectorielle.
/// </summary>
class PlayerShip : public GameObject
{
	static const float MAX_SPEED;
public:
	PlayerShip();
	/// <summary>
	/// Deplace le vaisseau dans l'espace
	/// On ajoute la nouvelle pouss�e � la pouss�e actuelle
	/// On limite la vitesse totale
	/// Puis on t�l�porte le vaisseau s'il arrive � un bout de l'�cran.
	/// </summary>
	/// <param name="force">La pouss�e ajout� � ce frame.</param>
	/// <param name="rotation">La rotation ajout� � ce frame.</param>

	
	const sf::Vector2f& getVectorialThrust() const;
	bool update(float elapsedTime, float thrustValue, float rotationValue);
private:
	/// <summary>
	/// Limiter la pouss�e � la vitesse maximale
	/// </summary>
	void setMaximumThrust();
	void handleOutOfBoundsPosition();
	sf::Vector2f vectorialThrust;
	float shipThrust;
};


