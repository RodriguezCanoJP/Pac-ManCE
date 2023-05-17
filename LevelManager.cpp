//
// Created by yitzy on 16/05/23.
//

#include "Headers/LevelManager.h"

LevelManager::LevelManager(char mapa[][22]) {
    nivel = 4;
    createEnemy(mapa);
}

void LevelManager::createEnemy(char mapa[][22]) {
    for(int i=0; i < nivel; i++){
        enemigos.push_back(new Enemigo);
    }
    switch (nivel) {
        case 1:
            enemigos[0]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);
            break;
        case 2:
            enemigos[0]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);
            enemigos[1]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 8*CELL_SIZE);
            break;
        case 3:
            enemigos[0]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);
            enemigos[1]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 8*CELL_SIZE);
            enemigos[2]->setSprite(ALIGN + 9*CELL_SIZE,ALIGN + 9*CELL_SIZE);
            break;
        case 4:
            enemigos[0]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 7*CELL_SIZE);
            enemigos[1]->setSprite(ALIGN + 10*CELL_SIZE,ALIGN + 8*CELL_SIZE);
            enemigos[2]->setSprite(ALIGN + 9*CELL_SIZE,ALIGN + 9*CELL_SIZE);
            enemigos[3]->setSprite(ALIGN + 11*CELL_SIZE,ALIGN + 9*CELL_SIZE);
            break;
    }
    for (int i = 0; i < nivel; ++i) {
        enemigos[i]->setWall(mapa);
    }
}



void LevelManager::updateEnemies(char mapa[][22]) {
    for (int i = 0; i < nivel; ++i) {
        enemigos[i]->update(mapa);
    }
}

void LevelManager::drawEnemies(sf::RenderWindow& r_window) {
    for (int i = 0; i < nivel; ++i) {
        r_window.draw(enemigos[i]->getSprite());
    }
}

LevelManager::~LevelManager() {
}

void LevelManager::search() {
    for (int i = 0; i < nivel; ++i) {
        enemigos[i]->pathfind();
    }
}

void LevelManager::enemyPath(char (*mapa)[22]){
    for (int i = 0; i < nivel; ++i) {
        int x = (enemigos[i]->getX()-ALIGN)/CELL_SIZE;
        int y = (enemigos[i]->getY()-ALIGN)/CELL_SIZE;
        std::vector<std::pair<int,int>> path = aStar(mapa, y, x);
        enemigos[i]->setPath(path);
    }
}

