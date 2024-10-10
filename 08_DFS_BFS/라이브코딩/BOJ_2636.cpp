#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int row, col;
int graph[100][100] = {0, };
bool visited[100][100] = {false, };
int result, ti = 0;
int cnt = 0; //녹인 치즈의 수

//상하좌우 탐색용
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool bfs(){
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];

            if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                //치즈가 없는 공기공간
                if(graph[nr][nc] == 0 && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});  
                    }                

                //치즈가 있는 공간
                if(graph[nr][nc] == 1 && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    graph[nr][nc] = 0;
                    cnt++;
                }
            }
        }
    }

    if(cnt == 0){
        return true;
    }
    else{
        result = cnt;
        return false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> graph[i][j];
        }
    }

    while(true){
        if(bfs()){ // 녹은 치즈가 하나도 없는 경우
            break;
        }
        memset(visited, false, sizeof(visited));
        cnt = 0;
        ti++;
    }
    cout << ti << "\n" << result;
}