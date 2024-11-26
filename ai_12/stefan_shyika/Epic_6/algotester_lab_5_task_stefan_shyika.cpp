#include <iostream>
#include <queue>

using namespace std;

//BFS algorithm
int main(){
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;
    x--;
    y--;
    int map[N][M];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    map[x][y] = 0;
    q.push({x,y});

    //the order of numbers will be reversed at first
    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        int curr_height = map[curr_x][curr_y];
        q.pop();

        for (int i = 0; i < 4; i++){
            int new_x = curr_x + dx[i];
            int new_y = curr_y + dy[i];

            //check if the coordinates are not out of bounds and are not altered yet
            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && map[new_x][new_y] == -1){
                map[new_x][new_y] = curr_height + 1;
                q.push({new_x, new_y});
            } 
        }
    }

    //find the max value of the map
    int max = map[0][0];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] > max) max = map[i][j];
        }
    }

    //reverse the heights
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = max - map[i][j];
            cout << map[i][j] << " ";
        }
        cout << endl;
    }


    
}