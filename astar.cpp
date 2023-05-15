//
// Created by juanpablo on 15/05/23.
//
#include "astar.h"




bool isValid(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int valueH(int x, int y, int final_x, int final_y){
    return abs(x - final_x) + abs(y-final_y);
}

vector<pair<int,int>> getPath(int prev[N][M], int start_x, int start_y, int final_x, int final_y){
    vector<pair<int,int>> path;
    int y = final_y;
    int x = final_x;

    while(x != start_x && y != start_y){
        path.emplace_back(x,y);
        int tempx = prev[x][y] /M;
        int tempy = prev[x][y] % M;
        x = tempx;
        y = tempy;
    }

    path.push_back({start_x, start_y});
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int,int>> aStar(char mapa[N][M], int start_x, int start_y, int final_x, int final_y){
    bool vistiados[N][M] = {0};
    int dist[N][M];
    int prev[N][M];

    for(int i=0; i<N; i++){
        for(int j=0; j<M ; j++){
            dist[i][j] = INF;
            prev[i][j] = -1;
        }
    }
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
    pq.push({0, {start_x, start_y}});
    dist[start_x][start_y] = 0;

    while(!pq.empty()){
        pair<int,pair<int,int>> curr = pq.top();
        pq.pop();

        int x = curr.second.first;
        int y = curr.second.second;
        int currDist = curr.first;

        if(vistiados[x][y]){
            continue;
        }

        vistiados[x][y] = true;

        if(x == final_x && y == final_y){
            break;
        }

        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(!isValid(new_x, new_y) || vistiados[new_x][new_y] || mapa[new_x][new_y] == '#'){
                continue;
            }

            int newDist = currDist + 1;
            int h = valueH(new_x, new_y, final_x, final_y);
            int total = newDist + h;

            if(total < dist[new_x][new_y]){
                dist[new_x][new_y] = total;
                prev[new_x][new_y] = x * M + y;
                pq.push({total, {new_x, new_y}});
            }
        }
    }
    vector<pair<int,int>> path = getPath(prev, start_x, start_y, final_x, final_y);
    return path;
}