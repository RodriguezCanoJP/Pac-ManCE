//
// Created by juanpablo on 08/05/23.
//
#include "Headers/DrawMap.h"
#include "Headers/Variables.h"
#include "Headers/astar.h"
#include "Maps.cpp"
#include "Headers/powerMod.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
    window.setFramerateLimit(60);

    Jugador jugador;
    jugador.setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 15*CELL_SIZE);

    Enemigo enemigo;
    enemigo.setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);

    Mapas map;

    enemigo.setWall(map.mapa1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color(34,178,193));
        draw_map(window, map.mapa1, jugador, enemigo);
        jugador.update(map.mapa1);
        jugador.collect(map.mapa1);
        enemigo.update(map.mapa1);
        if(jugador.getPuntaje()){
            setPower(map.mapa1);
            int x = (enemigo.getX()-ALIGN)/CELL_SIZE;
            int y = (enemigo.getY()-ALIGN)/CELL_SIZE;
            std::vector<std::pair<int,int>> path = aStar(map.mapa1, y, x);
            enemigo.setPath(path);
        }
        enemigo.pathfind();
        window.display();
    }


}
