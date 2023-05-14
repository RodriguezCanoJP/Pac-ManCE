//
// Created by juanpablo on 08/05/23.
//
#include "DrawMap.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
    window.setFramerateLimit(60);

    Jugador jugador;


    char maparr[21][22]{
        " ################### ",
        " #........#........# ",
        " #.##.###.#.###.##.# ",
        " #.................# ",
        " #.##.#.#####.#.##.# ",
        " #....#...#...#....# ",
        " ####.###.#.###.#### ",
        "    #.#...0...#.#    ",
        "#####.#.##=##.#.#####",
        "........#123#........",
        "#####.#.#####.#.#####",
        "    #.#.......#.#    ",
        " ####.#.#####.#.#### ",
        " #........#........# ",
        " #.##.###.#.###.##.# ",
        " #..#.....P.....#..# ",
        " ##.#.#.#####.#.#.## ",
        " #....#...#...#....# ",
        " #.######.#.######.# ",
        " #.................# ",
        " ################### "
    };
    

    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color(34,178,193));
        jugador.update();
        draw_map(window, maparr, jugador);
        window.display();
    }


}
