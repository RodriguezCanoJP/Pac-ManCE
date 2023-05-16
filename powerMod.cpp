//
// Created by juanpablo on 15/05/23.
//
#include "Headers/powerMod.h"

void setPower(char grid[21][22]){
    srand(time(0));
    int x;
    int y;

    while(true){
        x = 1 + rand()%19;
        y = 1 + rand()%20;
        if(grid[x][y] != '#'){
           break;
        }
    }

    grid[x][y] = 'o';

}