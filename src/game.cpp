#include "game.h"

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <iostream>

Game::Game() = default;

void Game::Init()
{
    window_.create(sf::VideoMode(1280, 720), "SAE Platformer");
    window_.setVerticalSyncEnabled(true);
    if (!wall_.loadFromFile("data/sprites/wall.jpg"))
    {
        std::cerr << "Texture Eror\n";
    }
    sprite_.setTexture(wall_);
    sprite_.setOrigin(wall_.getSize().x / 2.0f , wall_.getSize().y / 2.0f);

    player_.Init();
}

void Game::Loop()
{
    sf::Clock gameClock_;
    while(window_.isOpen())
    {
        auto dt = gameClock_.restart();
        sf::Event event;
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window_.close();
                return;
            }
            if (event.type == sf::Event::Resized)
            {
                auto view = window_.getView();
                view.setSize(event.size.width, event.size.height);
                window_.setView(view);
            }
        }

        player_.Update(dt.asSeconds());
        //Window view follows the player character
        auto view = window_.getView();
        view.setCenter(player_.GetPosition());
        window_.setView(view);


        window_.clear();
        const auto windowsSize = window_.getSize();
        sprite_.setPosition(windowsSize.x / 2.0f, windowsSize.y / 2.0f);
        window_.draw(sprite_);

        player_.Render(window_);

        window_.display();
    }
}