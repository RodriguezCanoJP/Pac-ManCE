//
// Created by juanpablo on 15/05/23.
//
#include "Headers/astar.h"

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int valueH(int x, int y, int final_x, int final_y) {
    return abs(x - final_x) + abs(y - final_y);
}

pair<int,int> findPower(char mapa[N][M]){
    pair<int,int> dest;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(mapa[i][j] == 'o'){
                dest = {i,j};
            }
        }
    }
    return dest;
}

vector<pair<int, int>> getPath(int prev[N][M], int startX, int startY, int destX, int destY) {
    vector<pair<int,int>> path;
    int x = destX;
    int y = destY;

    while (x != startX || y != startY) {
        path.push_back({x, y});
        int tempX = prev[x][y] / M;
        int tempY = prev[x][y] % M;
        x = tempX;
        y = tempY;
    }

    path.push_back({startX, startY});
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int, int>> aStar(char grid[N][M], int startX, int startY) {
    pair<int,int> dest = findPower(grid);
    int destX = dest.first;
    int destY = dest.second;
    bool visited[N][M] = {false};
    int dist[N][M];
    int prev[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;
            prev[i][j] = -1;
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {startX, startY}});
    dist[startX][startY] = 0;

    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int x = curr.second.first;
        int y = curr.second.second;
        int currDist = curr.first;

        if (visited[x][y]) {
            continue;
        }

        visited[x][y] = true;

        if (x == destX && y == destY) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (!isValid(newX, newY) || visited[newX][newY] || grid[newX][newY] == '#') {
                continue;
            }

            int G = currDist + 1;
            int h = valueH(newX, newY, destX, destY);
            int F = G + h;

            if (F < dist[newX][newY]) {
                dist[newX][newY] = F;
                prev[newX][newY] = x * M + y;
                pq.push({F, {newX, newY}});
            }
        }
    }
    vector<pair<int, int>> path = getPath(prev, startX, startY, destX, destY);
    return path;
}