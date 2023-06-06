#include "Player.h"
#include <iostream>
#include "Math.h"
#include <algorithm>


Player::Player() :
    playerSpeed(0.5f), hp(100),
    bulletMaxFireRate(100.0f), bulletFireRateTimer(0),
    skeletonMaxDamadgeRate(1000.0f), skeletonDamageRate(0),
    boss1MaxDamadgeRate(1000.0f), boss1DamageRate(0),
    boss2MaxDamadgeRate(1000.0f), boss2DamageRate(0),
    rasengunMaxFireRate(3000.0f), rasengunFireRateTimer(0),
    amaterasuMaxFireRate(3000.0f), amaterasuFireRateTimer(0),
    fireballMaxFireRate(3000.0f), fireballFireRateTimer(0),
    goldenAtclMaxFireRate(3000.0f), goldenAtcFireRateTimer(0),
    rasenshurikenlMaxFireRate(3000.0f), rasenshurikenFireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent); 
    boundingRectangle.setOutlineColor(sf::Color::Red); 
    boundingRectangle.setOutlineThickness(1);
    hp = 100;
    size = sf::Vector2i(24, 32);  
}

void Player::Load()
{
    
    if (texture.loadFromFile("Assets/Player/Textures/FumikoSpritesheet.png")) {
        std::cout << "Hero Loaded\n"; 
        
        if (font.loadFromFile("Assets/Fonts/arial.ttf"))
        {
            std::cout << "Font loaded\n";
            healthText.setFont(font);
            healthText.setString(std::to_string(hp));
        }
        
        int XIndex = 4;
        int YIndex = 2;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(100, 100));

        sprite.scale(sf::Vector2f(2, 2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
        std::cout << "ERROR\n";
}

void Player::Update(double deltaTime, sf::Vector2f& mousePosition)
{

    //Moving up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite.getPosition().y > 0) {
        //take current position of image
        sf::Vector2f position = sprite.getPosition();
        //add pixels to coordinate to move it
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * (float)deltaTime);
    }
    //Moving down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite.getPosition().y + size.y * sprite.getScale().y < 1080) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * (float)deltaTime);
    }
    //Moving left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite.getPosition().x > 0) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * (float)deltaTime);
    }
    //Moving right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x + size.x * sprite.getScale().x < 1920) {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * (float)deltaTime);
    }
    //--------------------------BULLET--------------------------
    bulletFireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && bulletFireRateTimer >= bulletMaxFireRate)
    {
        bullets.push_back(new Bullet());
        int i = bullets.size() - 1;
        bullets[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        bullets[i]->Load();
        bulletFireRateTimer = 0;
    }
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        bullets[i]->Update(deltaTime);
        
    }
    //--------------------------BULLET--------------------------
    //--------------------------RASENGUN------------------------
    rasengunFireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && rasengunMaxFireRate <= rasengunFireRateTimer)
    {
        rasenguns.push_back(new Rasengun());
        int i = rasenguns.size() - 1;
        rasenguns[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        rasenguns[i]->Load();
        rasengunFireRateTimer = 0;
    }
    for (size_t i = 0; i < rasenguns.size(); ++i)
    {
        rasenguns[i]->Update(deltaTime);

    }
    //--------------------------RASENGUN------------------------
    //--------------------------AMATERASU------------------------
    amaterasuFireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && amaterasuMaxFireRate <= amaterasuFireRateTimer)
    {
        amaterasus.push_back(new Amaterasu());
        int i = amaterasus.size() - 1;
        amaterasus[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        amaterasus[i]->Load();
        amaterasuFireRateTimer = 0;
    }
    for (size_t i = 0; i < amaterasus.size(); i++)
    {
        amaterasus[i]->Update(deltaTime);
    }
    //--------------------------AMATERASU------------------------
    //--------------------------FIREBALL------------------------
    fireballFireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && fireballMaxFireRate <= fireballFireRateTimer)
    {
        fireball.push_back(new Fireball());
        int i = fireball.size() - 1;
        fireball[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireball[i]->Load();
        fireballFireRateTimer = 0;
    }
    for (size_t i = 0; i < fireball.size(); i++)
    {
        fireball[i]->Update(deltaTime);
    }
    //--------------------------FIREBALL------------------------
    //--------------------------GOLDEN--------------------------
    goldenAtcFireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && goldenAtclMaxFireRate <= goldenAtcFireRateTimer)
    {
        goldenAtc.push_back(new GoldenAtc());
        int i = goldenAtc.size() - 1;
        goldenAtc[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        goldenAtc[i]->Load();
        goldenAtcFireRateTimer = 0;
    }
    for (size_t i = 0; i < goldenAtc.size(); i++)
    {
        goldenAtc[i]->Update(deltaTime);
    }
    //--------------------------GOLDEN--------------------------
    //--------------------------rasenshuriken--------------------------
    rasenshurikenFireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && rasenshurikenlMaxFireRate <= rasenshurikenFireRateTimer)
    {
        rasenshuriken.push_back(new Rasenshuriken());
        int i = rasenshuriken.size() - 1;
        rasenshuriken[i]->Initialize(sprite.getPosition(), mousePosition, 0.5f);
        rasenshuriken[i]->Load();
        rasenshurikenFireRateTimer = 0;
    }
    for (size_t i = 0; i < rasenshuriken.size(); i++)
    {
        rasenshuriken[i]->Update(deltaTime);
    }
    //--------------------------rasenshuriken--------------------------
    //--------------------------HEALTH--------------------------
    healthText.setString(std::to_string(hp));
    healthText.setPosition(sprite.getPosition());
    boundingRectangle.setPosition(sprite.getPosition());
}

void Player::UpdateSkeleton(double deltaTime, Skeleton*& skeleton)
{
    //--------------------------BULLET--------------------------
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(bullets[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds())) 
            {
                skeleton->ChangeHealth(-100); 
                bullets.erase(bullets.begin() + i); 
                //std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------BULLET--------------------------
    //--------------------------RASENGUN------------------------
    for (size_t i = 0; i < rasenguns.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(rasenguns[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds()))
            {
                skeleton->ChangeHealth(-50);
                rasenguns.erase(rasenguns.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------RASENGUN------------------------
    //--------------------------AMATERASUS----------------------
    for (size_t i = 0; i < amaterasus.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(amaterasus[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds()))
            {
                skeleton->ChangeHealth(-50);
                amaterasus.erase(amaterasus.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------AMATERASUS----------------------
    //--------------------------FIREBALL----------------------
    for (size_t i = 0; i < fireball.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(fireball[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds()))
            {
                skeleton->ChangeHealth(-50);
                fireball.erase(fireball.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------FIREBALL----------------------
    //--------------------------GOLDEN----------------------
    for (size_t i = 0; i < goldenAtc.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(goldenAtc[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds()))
            {
                skeleton->ChangeHealth(-50);
                goldenAtc.erase(goldenAtc.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------GOLDEN----------------------
    //--------------------------rasenshuriken----------------------
    for (size_t i = 0; i < rasenshuriken.size(); ++i)
    {
        if (skeleton->health > 0) {
            if (Math::DidRectCollide(rasenshuriken[i]->GetGlobalBounds(), skeleton->sprite.getGlobalBounds()))
            {
                skeleton->ChangeHealth(-50);
                rasenshuriken.erase(rasenshuriken.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------rasenshuriken----------------------
    //--------------------------SKELETON------------------------
    boundingRectangle.setPosition(sprite.getPosition());
    skeletonDamageRate += deltaTime;
    if (Math::DidRectCollide(skeleton->sprite.getGlobalBounds(), this->sprite.getGlobalBounds()) && skeletonDamageRate >= skeletonMaxDamadgeRate)
    {
        hp--;
        skeletonDamageRate = 0;
        //std::cout << "Collision" << "\n";
    }
    healthText.setString(std::to_string(hp));
    healthText.setPosition(sprite.getPosition());
    //--------------------------SKELETON------------------------
}

void Player::Update_Boss_1(double deltaTime, Boss_1*& boss_1)
{
    //--------------------------BULLET--------------------------
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        //bullets[i]->Update(deltaTime);
        if (boss_1->health > 0) {
            if (Math::DidRectCollide(bullets[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds()))
            {
                boss_1->ChangeHealth(-100);
                bullets.erase(bullets.begin() + i);
                //std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------BULLET--------------------------
    //--------------------------RASENGUN------------------------
    for (size_t i = 0; i < rasenguns.size(); ++i)
    {
        if (boss_1->health > 0) {
            if (Math::DidRectCollide(rasenguns[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds()))
            {
                boss_1->ChangeHealth(-50);
                rasenguns.erase(rasenguns.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------RASENGUN------------------------
    //--------------------------AMATERASUS----------------------
    for (size_t i = 0; i < amaterasus.size(); ++i)
    {
        if (boss_1->health > 0) {
            if (Math::DidRectCollide(amaterasus[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds()))
            {
                boss_1->ChangeHealth(-50);
                amaterasus.erase(amaterasus.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------AMATERASUS----------------------
    //--------------------------BOSS1---------------------------
    boundingRectangle.setPosition(sprite.getPosition());
    boss1DamageRate += deltaTime;
    if (Math::DidRectCollide(boss_1->sprite.getGlobalBounds(), this->sprite.getGlobalBounds()) && boss1DamageRate >= boss1MaxDamadgeRate)
    {
        hp-=50;
        boss1DamageRate = 0;
        //std::cout << "Collision" << "\n";
    }
    healthText.setString(std::to_string(hp));
    healthText.setPosition(sprite.getPosition());
    //--------------------------BOSS1---------------------------
    //--------------------------FIREBALL----------------------
    for (size_t i = 0; i < fireball.size(); ++i)
    {
        if (boss_1->health > 0) {
            if (Math::DidRectCollide(fireball[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds()))
            {
                boss_1->ChangeHealth(-50);
                fireball.erase(fireball.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------FIREBALL---------------------- 
    //--------------------------GOLDEN----------------------
    for (size_t i = 0; i < goldenAtc.size(); ++i) 
    { 
        if (boss_1->health > 0) { 
            if (Math::DidRectCollide(goldenAtc[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds())) 
            { 
                boss_1->ChangeHealth(-50); 
                goldenAtc.erase(goldenAtc.begin() + i); 
                std::cout << "Collision" << "\n"; 
            }
        }
    }
    //--------------------------GOLDEN----------------------
    //--------------------------rasenshuriken----------------------
    for (size_t i = 0; i < rasenshuriken.size(); ++i)
    {
        if (boss_1->health > 0) {
            if (Math::DidRectCollide(rasenshuriken[i]->GetGlobalBounds(), boss_1->sprite.getGlobalBounds()))
            {
                boss_1->ChangeHealth(-50);
                rasenshuriken.erase(rasenshuriken.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------rasenshuriken----------------------
}

void Player::Update_Boss_2(double deltaTime, Boss_2*& boss_2)
{
    for (size_t i = 0; i < bullets.size(); ++i)
    {
        //bullets[i]->Update(deltaTime);
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(bullets[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-100);
                bullets.erase(bullets.begin() + i);
                //std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------RASENGUN------------------------
    for (size_t i = 0; i < rasenguns.size(); ++i)
    {
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(rasenguns[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-50);
                rasenguns.erase(rasenguns.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------RASENGUN------------------------
    //--------------------------AMATERASUS----------------------
    for (size_t i = 0; i < amaterasus.size(); ++i)
    {
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(amaterasus[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-50);
                amaterasus.erase(amaterasus.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------AMATERASUS----------------------
    //--------------------------FIREBALL----------------------
    for (size_t i = 0; i < fireball.size(); ++i)
    {
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(fireball[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-50);
                fireball.erase(fireball.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------BOSS2---------------------------
    boundingRectangle.setPosition(sprite.getPosition());
    boss2DamageRate += deltaTime;
    if (Math::DidRectCollide(boss_2->sprite.getGlobalBounds(), this->sprite.getGlobalBounds()) && boss2DamageRate >= boss2MaxDamadgeRate)
    {
        hp -= 75;
        boss2DamageRate = 0;
        //std::cout << "Collision" << "\n";
    }
    healthText.setString(std::to_string(hp));
    healthText.setPosition(sprite.getPosition());
    //--------------------------BOSS2---------------------------
    //--------------------------GOLDEN----------------------
    for (size_t i = 0; i < goldenAtc.size(); ++i)
    {
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(goldenAtc[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-50);
                goldenAtc.erase(goldenAtc.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------GOLDEN----------------------
    //--------------------------rasenshuriken----------------------
    for (size_t i = 0; i < rasenshuriken.size(); ++i)
    {
        if (boss_2->health > 0) {
            if (Math::DidRectCollide(rasenshuriken[i]->GetGlobalBounds(), boss_2->sprite.getGlobalBounds()))
            {
                boss_2->ChangeHealth(-50);
                rasenshuriken.erase(rasenshuriken.begin() + i);
                std::cout << "Collision" << "\n";
            }
        }
    }
    //--------------------------rasenshuriken----------------------
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite); 
    window.draw(boundingRectangle);
    window.draw(healthText);
    for (size_t i = 0; i < bullets.size(); ++i) 
        bullets[i]->Draw(window); 
    for (size_t i = 0; i < rasenguns.size(); ++i)
        rasenguns[i]->Draw(window);
    for (size_t i = 0; i < amaterasus.size(); ++i)
        amaterasus[i]->Draw(window);
    for (size_t i = 0; i < fireball.size(); ++i)
        fireball[i]->Draw(window);
    for (size_t i = 0; i < goldenAtc.size(); ++i)
        goldenAtc[i]->Draw(window);
    for (size_t i = 0; i < rasenshuriken.size(); ++i)
        rasenshuriken[i]->Draw(window);
}