//
// Created by juanpablo on 15/05/23.
//

#ifndef PAC_MANCE_ASTAR_H
#define PAC_MANCE_ASTAR_H
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>



using namespace std;

const int N =21;
const int M = 22;
const int INF = 1e9;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0, 1, 0, -1};

pair<int,int> findPower(char mapa[N][M]);

bool isValid(int x, int y);

int valueH(int x, int y, int final_x, int final_y);

vector<pair<int,int>> getPath(int prev[N][M], int start_x, int start_y, int final_x, int final_y);

vector<pair<int,int>> aStar(char mapa[N][M], int start_x, int start_y);

#endif //PAC_MANCE_ASTAR_H
