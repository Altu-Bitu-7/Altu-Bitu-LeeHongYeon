#include <iostream>
#define INF (int)1e9
#define MAX 502

using namespace std;

int n, m;
int map[MAX][MAX];

int solution(){
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    for (int i =1; i <= n; i++){
    int cnt = 0;
        for (int j = 1; j <= n; j++){
            if(map[i][j] != INF || map[j][i] != INF){
                cnt++;
            }
        }
        if (cnt == n -1){
            ans++;
        }
    }
    return ans;
}

int main(){
    //입력
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            map[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    //연산 & 출력
    cout << solution();

}