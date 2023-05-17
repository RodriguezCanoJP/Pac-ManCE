//
// Created by juanpablo on 08/05/23.
//
#include "Headers/DrawMap.h"
#include "Headers/Variables.h"
#include "Headers/astar.h"
#include "Headers/powerMod.h"
#include "Headers/LevelManager.h"

int main(){
    sf::Font font;
    if (!font.loadFromFile("//home/yitzy/CLionProjects/Pac-ManCE/Font/static/OpenSans-Italic.ttf")){
        return EXIT_FAILURE;
    }

    sf::Font bold;
    if (!bold.loadFromFile("/home/yitzy/CLionProjects/Pac-ManCE/Font/static/OpenSans_SemiCondensed-Bold.ttf")){
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

    Mapas map;

    LevelManager manager(map.mapa1);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color(34,178,193));

        jugador.update(map.mapa1);
        jugador.collect(map.mapa1);
        puntaje.setString(to_string(jugador.getPuntaje()));
        vidas.setString(to_string(jugador.getHealth()));
        manager.updateEnemies(map.mapa1);
        if(jugador.isPowered()){
            setPower(map.mapa1);
            manager.enemyPath(map.mapa1);
        }
        manager.search();
        draw_map(window, map.mapa1, jugador);
        manager.drawEnemies(window);
        window.draw(texto_nivel);
        window.draw(puntaje);
        window.draw(vidas);
        window.draw(texto_puntaje);
        window.draw(texto_vidas);
        window.display();
    }


}
