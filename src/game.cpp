#include "game.h"

#include <iostream>


#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Sprite.hpp"

Game::Game() : player_(*this), platform_(*this), contactListener_(*this)
{
    
}

void Game::Init()
{
    world_.SetContactListener(&contactListener_);

    window_.create(sf::VideoMode(1280, 720),
        "SAE Platformer");
    window_.setVerticalSyncEnabled(true);
    window_.setFramerateLimit(10);
    if(!wall_.loadFromFile("data/sprites/wall.jpg"))
    {
        std::cerr << "Could not load texture!\n";
    }
    sprite_.setTexture(wall_);
    sprite_.setOrigin(wall_.getSize().x , wall_.getSize().y);

    if (!wall2_.loadFromFile("data/sprites/wall.jpg"))
    {
        std::cerr << "Could not load texture!\n";
    }
    sprite2_.setTexture(wall2_);
    sprite2_.setOrigin(wall2_.getSize().x+500, wall2_.getSize().y);

    if (!wall3_.loadFromFile("data/sprites/wall.jpg"))
    {
        std::cerr << "Could not load texture!\n";
    }
    sprite3_.setTexture(wall3_);
    sprite3_.setOrigin(wall3_.getSize().x -500, wall3_.getSize().y);

    player_.Init();
    platform_.Init1();
    platform_.Init2();
    platform_.Init3();
    platform_.InitF();
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
            if(event.type == sf::Event::Resized)
            {
                auto view = window_.getView();
                view.setSize(event.size.width, event.size.height);
                window_.setView(view);
            }
        }

        fixedTimer_ += dt.asSeconds();
        while(fixedTimer_ > fixedTimestep_)
        {
            world_.Step(fixedTimestep_, 8, 3);
            fixedTimer_ -= fixedTimestep_;
        }

        player_.Update(dt.asSeconds());
        //Window view follows the player character
        auto view = window_.getView();
        view.setCenter(player_.GetPosition());
        window_.setView(view);


        window_.clear(sf::Color::White);
        const auto windowsSize = window_.getSize();

        sprite_.setPosition(windowsSize.x/2.0f, windowsSize.y/2.0f);
        window_.draw(sprite_);

        sprite2_.setPosition(windowsSize.x / 2.0f, windowsSize.y / 2.0f);
        window_.draw(sprite2_);

        sprite3_.setPosition(windowsSize.x / 2.0f, windowsSize.y / 2.0f);
        window_.draw(sprite3_);

        

        player_.Render(window_);
        platform_.Render(window_);

        window_.display();
    }
}

b2Body* Game::CreateBody(const b2BodyDef& bodyDef)
{
    return world_.CreateBody(&bodyDef);
}

void Game::BeginContact(UserDataType userData, UserDataType userData1)
{
    if((userData == UserDataType::PLATFORM && userData1 == UserDataType::PLAYER_FOOT) ||
        (userData1 == UserDataType::PLATFORM && userData == UserDataType::PLAYER_FOOT)
        )
    {
        player_.BeginContactGround();
    }

    /*if ((userData == UserDataType::PLAYER_FOOT && userData1 == UserDataType::Flag))
    {                                                                                         gagner quand drapeau toucher      
        window_.close();
    }*/
}

void Game::EndContact(UserDataType userData, UserDataType userData1)
{
    if ((userData == UserDataType::PLATFORM && userData1 == UserDataType::PLAYER_FOOT) ||
        (userData1 == UserDataType::PLATFORM && userData == UserDataType::PLAYER_FOOT))
    {
        player_.EndContactGround();
    }
}
