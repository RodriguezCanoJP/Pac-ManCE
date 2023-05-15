//
// Created by juanpablo on 15/05/23.
//

#include "Enemigo.h"
#include "Variables.h"

Enemigo::Enemigo() {
    this->x = 0;
    this->y = 0;
    this->path.push_back({this->x,this->y});
}

Enemigo::~Enemigo() {

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
    this->path = new_path;
}

void Enemigo::update(char (*mapa)[22]) {
    int curr_x = (this->getX()-ALIGN)/CELL_SIZE;
    int curr_y = (this->getY()-ALIGN)/CELL_SIZE;
    if(!path.empty()){
        if(path[0].first > curr_x){
            this->y += VEL;
        }else if(path[0].first < curr_x){
            this->y -= VEL;
        }

        if(path[0].second > curr_y){
            this->x += VEL;
        }else if(path[0].second < curr_y){
            this->x -= VEL;
        }
        path.erase(path.begin());
    }
    this->sprite.setPosition(this->x, this->y);
}

int Enemigo::getX() {
    return this->x;
}

int Enemigo::getY() {
    return this->y;
}
