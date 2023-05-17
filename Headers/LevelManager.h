//
// Created by yitzy on 16/05/23.
//

#ifndef PAC_MANCE_LEVELMANAGER_H
#define PAC_MANCE_LEVELMANAGER_H
#include "Headers/Enemigo.h"
#include "Headers/Variables.h"
#include "Headers/astar.h"
#include "Maps.cpp"
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>

class LevelManager {
private:
    int nivel;
    std::vector<Enemigo*> enemigos;
public:
    LevelManager(char mapa[][22]);
    ~LevelManager();
    void createEnemy(char mapa[][22]);
    void updateEnemies(char mapa[][22]);
    void drawEnemies(sf::RenderWindow& r_window);
    void search();
    void enemyPath(char mapa[][22]);
    void resetEnemy();
    void changeMap();
};


#endif //PAC_MANCE_LEVELMANAGER_H
