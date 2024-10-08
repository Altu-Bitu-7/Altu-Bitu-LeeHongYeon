#include <iostream>
#include <vector>

using namespace std;

//상하좌우 탐색용
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

//바둑판 안에 있는지 체크
bool isInRange(int x, int y) {
    return x >= 0 && x < 19 && y >= 0 && y < 19;
}

int check(int board[19][19], int x, int y, pair<int, int>* win) {
    int target = board[x][y];
    
    for (int i = 0; i < 4; i++) {
        int cnt = 1;
        //다음 돌
        int nx = x + dx[i];
        int ny = y + dy[i];
        //이전 돌, 육목 체크용
        int px = x - dx[i];
        int py = y - dy[i];

        if (isInRange(px, py) && board[px][py] == target) {
            continue;
        }

        while (isInRange(nx, ny) && board[nx][ny] == target) {
            cnt++;
            nx += dx[i];
            ny += dy[i];
        }

        if (cnt == 5) {
            win->first = x;
            win->second = y;
            return target;
        }
    }

    return 0;
}

int main() {
    int board[19][19];
    pair<int, int> win;
    int ans = 0;

    //입력
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    bool found = false;
    for (int x = 0; x < 19 && !found; x++) {
        for (int y = 0; y < 19 && !found; y++) {
            if (board[x][y] != 0) {
                ans = check(board, x, y, &win);
                if (ans != 0) {
                    found = true;  // 오목을 찾으면 종료
                }
            }
        }
    }

    //출력
    cout << ans;
    if (ans != 0) {
        cout << "\n" << win.first + 1 << " " << win.second + 1;
    }
}