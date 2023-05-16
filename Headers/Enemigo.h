//
// Created by juanpablo on 15/05/23.
//

#ifndef PAC_MANCE_ENEMIGO_H
#define PAC_MANCE_ENEMIGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>


class Enemigo {
protected:
    int direccion;
    sf::Texture texture;
    sf::Sprite sprite;
    int x;
    int y;
    std::vector<std::pair<int,int>> path;
    int steps;
public:
    Enemigo();
    ~Enemigo();
    void setSprite(int x, int y);
    int getX();
    int getY();
    void setPath(std::vector<std::pair<int,int>> new_path);
    void pathfind();
    void update(char mapa[][22]);
    bool checkCollision(char mapa[][22]);
    sf::Sprite getSprite();

};


#endif //PAC_MANCE_ENEMIGO_H
