//
// Created by juanpablo on 08/05/23.
//
#include "Headers/DrawMap.h"
#include "Headers/Variables.h"
#include "Headers/astar.h"
#include "Maps.cpp"
#include "Headers/powerMod.h"

int main(){
    sf::Font font;
    if (!font.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Font/static/OpenSans-Italic.ttf")){
        return EXIT_FAILURE;
    }

    sf::Font bold;
    if (!bold.loadFromFile("/home/juanpablo/CLionProjects/Pac-ManCE/Font/static/OpenSans_SemiCondensed-Bold.ttf")){
        return EXIT_FAILURE;
    }

    sf::Text texto_puntaje("puntaje", font, 20);
    texto_puntaje.setFillColor(sf::Color::Red);
    texto_puntaje.setPosition(20, 20);

    sf::Text texto_nivel("Nivel", bold, 30);
    texto_nivel.setFillColor(sf::Color::Black);
    texto_nivel.setPosition(300, 15);

    sf::Text texto_vidas("vidas restantes", font, 20);
    texto_vidas.setFillColor(sf::Color::Red);
    texto_vidas.setPosition(600, 20);

    sf::Text puntaje(" ", font, 20);
    puntaje.setFillColor(sf::Color::White);
    puntaje.setPosition(100, 20);

    sf::Text vidas(" ", font, 20);
    vidas.setFillColor(sf::Color::White);
    vidas.setPosition(760, 20);

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
        puntaje.setString(to_string(jugador.getPuntaje()));
        vidas.setString(to_string(jugador.getHealth()));
        enemigo.update(map.mapa1);
        if(jugador.isPowered()){
            setPower(map.mapa1);
            int x = (enemigo.getX()-ALIGN)/CELL_SIZE;
            int y = (enemigo.getY()-ALIGN)/CELL_SIZE;
            std::vector<std::pair<int,int>> path = aStar(map.mapa1, y, x);
            enemigo.setPath(path);
        }
        enemigo.pathfind();
        window.draw(texto_nivel);
        window.draw(puntaje);
        window.draw(vidas);
        window.draw(texto_puntaje);
        window.draw(texto_vidas);
        window.display();
    }


}
