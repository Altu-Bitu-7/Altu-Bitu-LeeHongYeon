#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int x, y, d, g;
vector<int> dir_info;
int map[MAX][MAX];

int dx[] = {0, -1, 0 ,1};
int dy[] = {1, 0, -1 ,0};

void dragonCurve(){
    int size = dir_info.size();
    for(int i = size - 1; i >= 0; i--){
        int nD = (dir_info[i] + 1) % 4;
        x = x + dx[nD];
        y = y + dy[nD];
        map[x][y] = 1;

        dir_info.push_back(nD);
    }
}

int solution(int n){
    int cnt = 0;
    for (int i =0; i < n; i++){
        cin >> y >> x >> d >> g;
        dir_info.clear();
        map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = 1;

        dir_info.push_back(d);
        for (int j = 0; j < g; j++){
            dragonCurve();
        }
    }

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    //입력
    cin >> n;

    //연산 & 출력
    cout << solution(n);
}