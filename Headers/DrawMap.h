//
// Created by juanpablo on 08/05/23.
//

#ifndef PAC_MANCE_DRAWMAP_H
#define PAC_MANCE_DRAWMAP_H

#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Enemigo.h"

void draw_map(sf::RenderWindow& r_window, char map[][22], Jugador jugador, Enemigo enemigo);
#endif //PAC_MANCE_DRAWMAP_H
