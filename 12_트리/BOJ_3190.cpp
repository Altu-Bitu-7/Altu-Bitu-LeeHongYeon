#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<int>> map;
vector<pair<int, int>> apple;
queue<pair<int, char>> dir;
deque<pair<int, int>> dq;

int solution(int n){
    int ans = 0;
    int dir_idx = 1;
    while(true){
        ans++;
        int nRow = dq.back().first + dy[dir_idx];
        int nCol = dq.back().second + dx[dir_idx];
        
        if (nRow <= 0 || nRow > n || nCol <= 0 || nCol > n || map[nRow][nCol] == 1){
            break;
        }

        if(map[nRow][nCol] != 2){
            map[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        map[nRow][nCol] = 1;
        dq.push_back({nRow, nCol});

        if(ans == dir.front().first){
            char ch = dir.front().second;
            if(ch == 'D'){
                dir_idx = (dir_idx + 1) % 4;
            }
            else{
                dir_idx = (dir_idx - 1 + 4) % 4;
            }
            dir.pop();
        }
    }

    return ans;
}

int main(){
    int n, k, l;
    //입력
    cin >> n >> k;
    map.resize(n+1, vector<int>(n+1, 0));
    apple.resize(k);

    for (int i = 0; i < k; i++){
        cin >> apple[i].first >> apple[i].second;
        map[apple[i].first][apple[i].second] = 2;
    }

    cin >> l;
    
    for(int i = 0; i < l; i++){
        int x;
        char c;
        cin >> x >> c;
        dir.push({x, c});
    }

    //연산 & 출력
    map[1][1] = 1;
    dq.push_back({1, 1});
    cout << solution(n);
}