#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m, x, y;
int graph[101][101] = {0, }; //인접행렬
bool visited[101] = {false, };
int ans = -1;

void dfs(int from, int cnt){
    visited[from] = true;
    if(from == b){
        ans = cnt;
        return;
    }

    for (int i = 1; i <= n; i++){
        if(graph[from][i] == 1 && !visited[i]){
            dfs(i, cnt + 1);
        }
    }
}

int main(){
    
    //입력
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1; //부모 자식간은 1촌 관계
    }

    //연산
    dfs(a, 0);

    //출력
    cout << ans;

}