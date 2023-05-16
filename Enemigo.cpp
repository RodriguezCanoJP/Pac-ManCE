//
// Created by juanpablo on 15/05/23.
//

#include <utility>

#include "Headers/Enemigo.h"
#include "Headers/Variables.h"

Enemigo::Enemigo() {
    this->x = 0;
    this->y = 0;
    this->direccion = 3;
    steps = CELL_SIZE/VEL_ENEMIGO + 1;
}

Enemigo::~Enemigo() {

}

int Enemigo::getX() {
    return this->x;
}

int Enemigo::getY() {
    return this->y;
}

void Enemigo::setSprite(int x, int y) {
    this->x += x;
    this->y += y;
    this->texture.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Images/ghost.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(this->x, this->y);
}

sf::Sprite Enemigo::getSprite() {
    return this->sprite;
}

void Enemigo::setPath(std::vector<std::pair<int, int>> new_path) {
    this->path = std::move(new_path);
}

void Enemigo::pathfind() {
    int curr_x = (this->getX()-ALIGN)/CELL_SIZE;
    int curr_y = (this->getY()-ALIGN)/CELL_SIZE;
    if(!path.empty()){
        if(path[0].first > curr_y){
            this->y += VEL_ENEMIGO;
        }else if(path[0].first < curr_y){
            this->y -= VEL_ENEMIGO;
        }

        if(path[0].second > curr_x){
            this->x += VEL_ENEMIGO;
        }else if(path[0].second < curr_x){
            this->x -= VEL_ENEMIGO;
        }
        this->steps -= 1;
        if(steps == 0){
            path.erase(path.begin());
            steps = CELL_SIZE/VEL_ENEMIGO + 1;
        }

    }
    this->sprite.setPosition(this->x, this->y);
}



void Enemigo::update(char (*mapa)[22]) {
    srand(time(0));

    if(this->path.empty()){
        switch (this->direccion) {
            case 0:
                this->y +=0;
                this->x +=0;
                break;
            case 1:
                this->y -= VEL_ENEMIGO;
                if(checkCollision(mapa)){
                    this->y += 1;
                    direccion = 1 + rand() % 4;
                    setWall(mapa);
                }
                break;
            case 2:
                this->y += VEL_ENEMIGO;
                if(checkCollision(mapa)){
                    this->y -= 1;
                    direccion = 1 + rand() % 4;
                    setWall(mapa);
                }
                break;
            case 3:
                this->x += VEL_ENEMIGO;
                if(checkCollision(mapa)){
                    this->x -= 1;
                    direccion = 1 + rand() % 4;
                    setWall(mapa);
                }
                break;
            case 4:
                this->x -= VEL_ENEMIGO;
                if(checkCollision(mapa)){
                    this->x += 1;
                    direccion = 1 + rand() % 4;
                    setWall(mapa);
                }
                break;
        }
        this->sprite.setPosition(this->x, this->y);
    }
}

bool Enemigo::checkCollision(char (*mapa)[22]) {
    bool collision = false;
    switch (direccion) {
        case 1:
            collision = this->getY() < this->wall.second + CELL_SIZE;
            break;
        case 2:
            collision = this->getY() + CELL_SIZE > this->wall.second;
            break;
        case 3:
            collision = this->getX() + CELL_SIZE > this->wall.first;
            break;
        case 4:
            collision = this->getX() < this->wall.first + CELL_SIZE;
            break;
    }
    return collision;
}

void Enemigo::setWall(char (*mapa)[22]) {
    int curr_x = (this->getX()-ALIGN)/CELL_SIZE;
    int curr_y = (this->getY()-ALIGN)/CELL_SIZE;
    int wall_posx = 0;
    int wall_posy = 0;
    switch (direccion) {
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
