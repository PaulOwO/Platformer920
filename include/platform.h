#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "user_data.h"

namespace sf {
    class RenderWindow;
}

class b2Body;
class Game;

class Platform
{
public:
    explicit Platform(Game& game);
    void Init1();
    void Init2();
    void Init3();
    void InitF(); //EndingFlag

    void Update(float dt);
    void Render(sf::RenderWindow& window);

private:
    Game& game_;
    b2Body* body_ = nullptr;
    const float scale_ = 3.0f;
    sf::Sprite sprite3_;
    sf::Sprite sprite2_;
    sf::Sprite sprite1_;
    sf::Sprite spriteF_;
    inline static bool isTextureLoaded_;
    inline static sf::Texture platformTexture_;
    inline static sf::Texture flagTexture_;
    const sf::Vector2f originPos = sf::Vector2f(1.0f, 3.0f);
    UserData platformUserData_ = { UserDataType::PLATFORM };
    UserData flagUserData_ = { UserDataType::PLATFORM };
};
