//
// Created by yitzy on 12/05/23.
//

#include "Headers/Backtracking.h"
#include <iostream>
#include <vector>
using namespace std;

const int ROW = 5, COL = 5; // Tamaño del laberinto

// Función auxiliar para imprimir la matriz del laberinto
void printMaze(int maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

// Función auxiliar para verificar si una posición es válida en el laberinto
bool isValid(int maze[][COL], int x, int y, bool visited[][COL]) {
    return x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 0 && !visited[x][y];
}

// Función principal de backtracking
bool solveMazeUtil(int maze[][COL], int x, int y, int destX, int destY, vector<pair<int, int>>& path, bool visited[][COL]) {
    // Si se llega al destino, devolver la ruta
    if (x == destX && y == destY) {
        return true;
    }

    // Comprobar movimientos arriba, abajo, izquierda y derecha
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++) {
        int nextX = x + row[i];
        int nextY = y + col[i];

        if (isValid(maze, nextX, nextY, visited)) {
            visited[nextX][nextY] = true;
            path.push_back(make_pair(nextX, nextY)); // Añadir el movimiento actual a la ruta

            // Llamada recursiva
            if (solveMazeUtil(maze, nextX, nextY, destX, destY, path, visited)) {
                return true;
            }

            // Si no se encontró la ruta, deshacer el movimiento y continuar con el siguiente movimiento
            visited[nextX][nextY];
        }
    }
}