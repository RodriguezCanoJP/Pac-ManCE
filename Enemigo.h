//
// Created by juanpablo on 15/05/23.
//

#ifndef PAC_MANCE_ENEMIGO_H
#define PAC_MANCE_ENEMIGO_H

#include <SFML/Graphics.hpp>
#include <vector>


class Enemigo {
protected:
    int direccion;
    sf::Texture texture;
    sf::Sprite sprite;
    int x;
    int y;
    std::vector<std::pair<int,int>> path;
public:
    Enemigo();
    ~Enemigo();
    void setSprite(int x, int y);
    int getX();
    int getY();
    void setPath(std::vector<std::pair<int,int>> new_path);
    void update(char mapa[][22]);
    sf::Sprite getSprite();

};


#endif //PAC_MANCE_ENEMIGO_H
