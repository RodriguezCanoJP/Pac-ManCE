#include "Jugador.h"

Jugador::Jugador() {
    this->health = 3;
    this->x = 0;
    this->y = 0;
}

Jugador::~Jugador() {
}

void Jugador::update(int vel) {
    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        direction = 0;
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        direction = 1;
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        direction = 2;
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        direction = 3;
    }

    switch (this->direction) {
        case 0:
            this->y -= vel;
            break;
        case 1:
            this->y += vel;
            break;
        case 2:
            this->x += vel;
            break;
        case 3:
            this->x -= vel;
            break;

    }
    this->sprite.setPosition(this->x, this->y);
}

int Jugador::getX() {
    return this->x;
}

int Jugador::getY() {
    return this->y;
}

sf::Sprite Jugador::getSprite() {
    return this->sprite;
}

void Jugador::getHit() {
    this->health --;
}

bool Jugador::isDead() {
    if(this->health <= 0){
        return true;
    }else{
        return false;
    }
}

void Jugador::setSprite(int x, int y) {
    this->texture.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Images/pacman.png");
    this->sprite.setTexture(texture);
    this->x += x;
    this->y += y;
    this->sprite.setPosition(this->x, this->y);
}
