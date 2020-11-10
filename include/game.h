#pragma once
#include "player_character.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "box2d/b2_world.h"

class Game
{
public:
    Game();
    void Init();
    void Loop();
private:
    sf::RenderWindow window_;
    sf::Texture wall_;
    sf::Sprite sprite_;
    b2World world_{b2Vec2(0.0f, 9.81f)};

    PlayerCharacter player_;
};