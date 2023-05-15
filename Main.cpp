//
// Created by juanpablo on 08/05/23.
//
#include "DrawMap.h"
#include "Variables.h"
#include "astar.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
    window.setFramerateLimit(60);

    Jugador jugador;
    jugador.setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 15*CELL_SIZE);

    Enemigo enemigo;
    enemigo.setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);

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
        " #..#..... .....#..# ",
        " ##.#.#.#####.#.#.## ",
        " #....#...#...#....# ",
        " #.######.#.######.# ",
        " #.................# ",
        " ################### "
    };

    char maparr2 [21] [22]{
            "#####################",
            "#......##...........#",
            "#.####...........###",
            "#......##...........#",
            "#...##...........##.#",
            "#......####.......###",
            "###.................#",
            "#........0.........#",
            "#.######.=..........#",
            "#.......123..........#",
            "#...............######",
            "#..........#####.....#",
            "#........#...........#",
            "#.......#............#",
            "#.......#...#........#",
            "#.......#............#",
            "#........ ..........#",
            "#...#...............#",
            "#....###............#",
            " #.................# ",
            " ################### "


    };

    std::vector<std::pair<int,int>> path = aStar(maparr, 1, 3, 13, 5);
    std::cout << "Distance: " << path.size() << "\n";

    enemigo.setPath(path);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color(34,178,193));
        draw_map(window, maparr, jugador, enemigo);
        jugador.update(maparr);
        enemigo.update(maparr);
        window.display();
    }


}
