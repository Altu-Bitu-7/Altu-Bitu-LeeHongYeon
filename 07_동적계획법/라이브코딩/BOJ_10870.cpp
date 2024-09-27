#include <bits/stdc++.h> //iostream, vector, 알고리즘 한번에 불러옴

using namespace std;

vector<vector<int>> board;
vector<vector<int>> check;
int n;

int recur(int x, int y){
    //벗어난 경우
    if (x >= n || y >= n){ 
        return 0;
    }
    //도착한 경우
    if (x == n-1 && y == n-1){ 
        return 1;
    }
    //탐생 중인 경우
    return recur(x + board[x][y], y) || recur(x, y + board[x][y]); //오른쪽이나 밑으로만 이동
}

int dp(int x, int y){
    //벗어난 경우
    if (x >= n || y >= n){ 
        return 0;
    }
    //도착한 경우
    if (x == n-1 && y == n-1){ 
        return 1;
    }

    if (check[x][y] != -1){
        return check[x][y]
    }
    //아직 방문하지 않은 경우
    check[x][y] = dp(x + board[x][y], y) || dp(x, y + board[x][y]);
    return check[x][y];
}

int main(){
    int c;

    //입력
    cin >> c;
    while (c--){
        cin >> n;
        board.assign(n, vector<int> (n, 0));
        check.assign(n, vector<int> (n, -1));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        //연산 & 출력
        if (recur(0, 0)){
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }


}