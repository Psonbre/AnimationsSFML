#include "InputBasedAnimation.h"

class ShipAnimation : public InputBasedAnimation {
private:
    int nbFrameInState;

public:
    ShipAnimation(sf::Sprite& sprite);

    bool init(const ContentManager& contentManager) override;

    void adjustNextFrame(const Inputs& inputs) override;
};