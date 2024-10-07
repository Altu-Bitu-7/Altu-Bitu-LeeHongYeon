#include <iostream>
#include <vector>
using namespace std;

int graph[101][101] = {0, }; //인접행렬 이용
bool visited[101] =  {false};
int cnt = 0; //감염된 컴퓨터 수

void dfs(int from, int n){
    visited[from] = true;
    for (int i = 1; i <= n; i++){
        if(graph[from][i] == 1 && !visited[i]){
                cnt++;
                dfs(i, n);
        }
    }
}

int main(){
    int n, m;

    //입력
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
    }
    //연산
    dfs(1, n); //1번 노드부터 시작

    //출력
    cout << cnt;
}