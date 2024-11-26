#include <iostream>
#include <vector>

using namespace std;

int n, m, r, c, d;
vector<vector<bool>> is_visited;
vector<vector<int>> room;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt = 1; // 현재 로봇청소기 위치는 미리 카운트

void solution() {
    for (int i = 0; i < 4; i++) {
        int next_d = (d + 3 - i) % 4; // 왼쪽 방향
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        // 경계 조건 확인 및 벽 확인
        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m || room[next_r][next_c] == 1) {
            continue;
        }

        // 청소하지 않은 영역 확인
        if (room[next_r][next_c] == 0 && !is_visited[next_r][next_c]) {
            is_visited[next_r][next_c] = true;
            r = next_r;
            c = next_c;
            d = next_d;
            cnt++;
            solution();
            return;
        }
    }

    // 후진
    int back_idx = (d + 2) % 4;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];

    // 후진 조건 확인
    if (back_r >= 0 && back_r < n && back_c >= 0 && back_c < m) {
        if (room[back_r][back_c] == 0) {
            r = back_r;
            c = back_c;
            solution();
        }
    }
}

int main() {
    // 입력
    cin >> n >> m >> r >> c >> d;
    room.resize(n, vector<int>(m));
    is_visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    // 초기 위치 방문 처리
    is_visited[r][c] = true;
    solution();

    // 출력
    cout << cnt;
}
