#include "Headers/Jugador.h"
#include "Headers/Variables.h"

Jugador::Jugador() {
    this->health = 3;
    this->x = 0;
    this->y = 0;
    puntaje = 0;
}

Jugador::~Jugador() {
}

int Jugador::getX() {
    return this->x;
}

int Jugador::getY() {
    return this->y;
}

void Jugador::getHit() {
    this->health --;
}

int Jugador::getPuntaje() {
    return this-> puntaje;
}

int Jugador::getHealth() {
    return this->health;
}


bool Jugador::isDead() {
    if(this->health <= 0){
        return true;
    }else{
        return false;
    }
}

bool Jugador::isPowered(){
    if(puntaje > 0 && puntaje % 200 == 0){
        puntaje += 1;
        return true;
    }else{
        return false;
    }
}

sf::Sprite Jugador::getSprite() {
    return this->sprite;
}

void Jugador::setSprite(int x, int y) {
    this->x += x;
    this->y += y;
    this->texture.loadFromFile("/home/yitzy/CLionProjects/Pac-ManCE/Images/pacman.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(this->x, this->y);
}



void Jugador::update(char mapa[][22]) {
    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->direction = 1;
        this->setWall(mapa);
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->direction = 2;
        this->setWall(mapa);
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->direction = 3;
        this->setWall(mapa);
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->direction = 4;
        this->setWall(mapa);
    }

    if(checkCollision(mapa)){
        this->direction = 0;
    }

    switch (this->direction) {
        case 0:
            this->y +=0;
            this->x +=0;
            break;
        case 1:
            this->y -= VEL;
            break;
        case 2:
            this->y += VEL;
            break;
        case 3:
            this->x += VEL;
            break;
        case 4:
            this->x -= VEL;
            break;


    }
    this->sprite.setPosition(this->x, this->y);
}



bool Jugador::checkCollision(char mapa[][22]) {
    bool collision = false;
    switch (direction) {
        case 1:
            collision = this->getY() - CELL_SIZE - 1 < this->wall.second;
            break;
        case 2:
            collision = this->getY() + CELL_SIZE > this->wall.second;
            break;
        case 3:
            collision = this->getX() + CELL_SIZE > this->wall.first;
            break;
        case 4:
            collision = this->getX() - CELL_SIZE - 1 < this->wall.first;
            break;
    }
    return collision;

}

void Jugador::collect(char (*mapa)[22]) {
    int curr_x = (this->getX()-ALIGN)/CELL_SIZE;
    int curr_y = (this->getY()-ALIGN)/CELL_SIZE;
    char obj = mapa[curr_y][curr_x];
    if(obj == '.'){
        puntaje += 5;
        mapa[curr_y][curr_x] = ' ';
    }else if(obj == 'o'){

    }
}



void Jugador::setWall(char (*mapa)[22]) {
    int curr_x = (this->getX()-ALIGN)/CELL_SIZE;
    int curr_y = (this->getY()-ALIGN)/CELL_SIZE;
    int wall_posx = 0;
    int wall_posy = 0;
    switch (direction) {
        case 1:
            for (int i = curr_y; i >= 0; i--) {
                if (mapa[i][curr_x] == '#') {
                    wall_posy = i*CELL_SIZE + ALIGN;
                    break;
                }
            }
            break;
        case 2:
            for (int i = curr_y; i < 21; i++) {
                if (mapa[i][curr_x] == '#') {
                    wall_posy = i*CELL_SIZE + ALIGN;
                    break;
                }
            }
            break;
        case 3:
            for (int i = curr_x; i < 22 ; i++) {
                if (mapa[curr_y][i] == '#') {
                    wall_posx = i*CELL_SIZE + ALIGN;
                    break;
                }
            }
            break;
        case 4:
            for (int i = curr_x; i >= 0; i--) {
                if (mapa[curr_y][i] == '#') {
                    wall_posx = i*CELL_SIZE + ALIGN;
                    break;
                }
            }
            break;
    }
    this->wall = {wall_posx, wall_posy};
}

