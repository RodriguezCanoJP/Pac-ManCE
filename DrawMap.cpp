//
// Created by juanpablo on 08/05/23.
//
#include "DrawMap.h"

void draw_map(sf::RenderWindow& r_window, char map[][22]){
    int CELL_SIZE = 16;
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Images/map.png");
    sprite.setTexture(texture);

    for(int i=0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            sprite.setPosition(CELL_SIZE * i, CELL_SIZE * j);

            switch (map[i][j]) {
                case '#': {
                    bool down = 0;
                    bool left = 0;
                    bool right = 0;
                    bool up = 0;

                    if (j < r_window.getSize().y - 1) {
                        if (map[i][1 + j] == '#') {
                            down = 1;
                        }
                    }


                    //Since we have warp tunnels, we need to draw them as if they're connected.
                    if (0 < i) {
                        if ('#' == map[i - 1][j]) {
                            left = 1;
                        }
                    } else {
                        left = 1;
                    }

                    if (i < r_window.getSize().x - 1) {
                        if ('#' == map[1 + i][j]) {
                            right = 1;
                        }
                    } else {
                        right = 1;
                    }


                    if (0 < j) {
                        if ('#' == map[i][j - 1]) {
                            up = 1;
                        }
                    }

                    //--------------------------------------------<         DISTRIBUTIVE PROPERTY!         >----------------------------
                    sprite.setTextureRect(
                            sf::IntRect(CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0, CELL_SIZE,
                                        CELL_SIZE));
                    r_window.draw(sprite);
                    break;
                }

                case 'o': {
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));

                    sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));

                    r_window.draw(sprite);

                    break;
                }

                case '.': {
                    sprite.setTextureRect(sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE));

                    r_window.draw(sprite);

                    break;
                }

                case '=': {
                    sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));

                    r_window.draw(sprite);
                }
            }
        }
    }
}
