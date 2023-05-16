//
// Created by juanpablo on 08/05/23.
//
#include "Headers/DrawMap.h"
#include "Headers/Variables.h"
void draw_map(sf::RenderWindow& r_window, char map[][22], Jugador jugador, Enemigo enemigo){
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Images/map24.png");
    sprite.setTexture(texture);
    r_window.draw(jugador.getSprite());
    r_window.draw(enemigo.getSprite());
    for(int i=0; i < 21; i++) {
        for (int j = 0; j < 22; j++) {
            sprite.setPosition(ALIGN + CELL_SIZE * j,ALIGN + CELL_SIZE * i);

            switch (map[i][j]) {
                case '#': {
                    bool down = 0;
                    bool left = 0;
                    bool right = 0;
                    bool up = 0;

                    if (j < r_window.getSize().y - 1) {
                        if (map[i][1 + j] == '#') {
                            right = 1;
                        }
                    }

                    if (0 < i) {
                        if ('#' == map[i - 1][j]) {
                            up = 1;
                        }
                    }

                    if (i < r_window.getSize().x - 1) {
                        if ('#' == map[1 + i][j]) {
                            down = 1;
                        }
                    }


                    if (0 < j) {
                        if ('#' == map[i][j - 1]) {
                            left = 1;
                        }
                    }

                    sprite.setTextureRect(sf::IntRect(CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0, CELL_SIZE,
                                        CELL_SIZE));
                    r_window.draw(sprite);
                    break;
                }

                case 'o': {
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
                    break;
                }
            }
        }
    }
}
