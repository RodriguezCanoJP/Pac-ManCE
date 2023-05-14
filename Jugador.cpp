#include "Jugador.h"
#include "Variables.h"

Jugador::Jugador() {
    this->health = 3;
    this->x = 0;
    this->y = 0;
}

Jugador::~Jugador() {
}

void Jugador::update() {
    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->direction = 0;
        this->setNextWall('u');
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->direction = 1;
        this->setNextWall('d');
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->direction = 2;
        this->setNextWall('r');
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->direction = 3;
        this->setNextWall('l');
    }

    switch (this->direction) {
        case 0:
            this->y -= VEL;
            break;
        case 1:
            this->y += VEL;
            break;
        case 2:
            this->x += VEL;
            break;
        case 3:
            this->x -= VEL;
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

void Jugador::setNextWall(char a) {
    this->next_wall = a;
}

bool Jugador::checkCollision(char mapa[][22]) {
    int curr_x = (this->getX()-ALIGN)/24;
    int curr_y = (this->getY()-ALIGN)/24;
    int wall_pos = 0;
    char current_pos = mapa[curr_x][curr_y];
    switch (direction) {
        case 0:
            for (int i = curr_y; i > 0; i--) {
                if (mapa[i][curr_x] == '#') {
                    wall_pos = i;
                    break;
                }
            }
            break;
        case 1:
            for (int i = curr_y; i > 0; i--) {
                if (mapa[i][curr_x] == '#') {
                    wall_pos = i;
                    break;
                }
            }
            break;
        case 2:
            for (int i = curr_y; i > 0; i--) {
                if (mapa[i][curr_x] == '#') {
                    wall_pos = i;
                    break;
                }
            }
            break;
        case 3:
            for (int i = curr_y; i > 0; i--) {
                if (mapa[i][curr_x] == '#') {
                    wall_pos = i;
                    break;
                }
            }
            break;


    }

}
