#include "platform.h"
#include "game.h"
#include <box2d/box2d.h>

Platform::Platform(Game& game) : game_(game)
{
    isTextureLoaded_ = false;
}

void Platform::Init1()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.jpg");
        isTextureLoaded_ = true;
    }
    sprite1_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(originPos.x, originPos.y);

    sprite1_.setPosition(
        originPos.x * game_.pixelToMeter,
        originPos.y * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite1_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite1_.setScale(scale_, scale_);

    b2Vec2 boxSize;
    boxSize.Set(
        textureSize.x / game_.pixelToMeter / 2.0f * scale_,
        textureSize.y / game_.pixelToMeter / 2.0f * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init2()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.jpg");
        isTextureLoaded_ = true;
    }
    sprite2_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(5,1 );

    sprite2_.setPosition(
        5 * game_.pixelToMeter,
        1 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite2_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite2_.setScale(scale_, scale_);

    b2Vec2 boxSize;
    boxSize.Set(
        textureSize.x / game_.pixelToMeter / 2.0f * scale_,
        textureSize.y / game_.pixelToMeter / 2.0f * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);

}

void Platform::Init3()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.jpg");
        isTextureLoaded_ = true;
    }
    sprite3_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(3, 2);

    sprite3_.setPosition(
        3 * game_.pixelToMeter,
        2 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite3_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite3_.setScale(scale_, scale_);

    b2Vec2 boxSize;
    boxSize.Set(
        textureSize.x / game_.pixelToMeter / 2.0f * scale_,
        textureSize.y / game_.pixelToMeter / 2.0f * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);

}

void Platform::InitF()
{
    if (!isTextureLoaded_)
    {
        flagTexture_.loadFromFile("data/sprites/flag.png");
        isTextureLoaded_ = true;
    }
    spriteF_.setTexture(flagTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(0, 0);

    spriteF_.setPosition(
        0 * game_.pixelToMeter,
        0 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = flagTexture_.getSize();
    spriteF_.setOrigin(textureSize.x , textureSize.y) ;
    spriteF_.setScale(scale_, scale_);

    b2Vec2 boxSize;
    boxSize.Set(
        textureSize.x / game_.pixelToMeter / 2.0f * scale_,
        textureSize.y / game_.pixelToMeter / 2.0f * scale_
    );

    b2PolygonShape flagShape;
    flagShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef flagFixtureDef;
    flagFixtureDef.isSensor = true;
    flagFixtureDef.userData = &flagUserData_;
    flagFixtureDef.shape = &flagShape;
    body_->CreateFixture(&flagFixtureDef);

}

void Platform::Update(float dt)
{
}

void Platform::Render(sf::RenderWindow& window)
{
    window.draw(sprite1_);
    window.draw(sprite2_);
    window.draw(sprite3_);
    window.draw(spriteF_);
}
