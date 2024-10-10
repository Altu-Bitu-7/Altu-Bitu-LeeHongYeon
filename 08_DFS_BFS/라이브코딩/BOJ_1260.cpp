#include <iostream>
#include <queue>
#include <cstring> //memset : 메모리 초기화 함수 사용 가능

using namespace std;

//전역변수 사용시 자동으로 0으로 초기화
int n, m, v;
int graph[1001][1001] = {0, }; //인접행렬 사용, 노드는 1번부터 시작이라 사이즈 1001로 설정
bool visited[1001] = {false, };
int dfs_ans[1001] = {0, };
int bfs_ans[1001] = {0, }; 

int idx = 0;

void dfs(int from){ //시작 노드 입력받음
    for (int i = 1; i <= n; i++){
        if(graph[from][i] == 1){
            if(!visited[i]){
                visited[i] = true;
                dfs_ans[idx++] = i;
                dfs(i);
            }
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for (int i = 1; i <= n; i++){
            if(graph[now][i] == 1){
                if(!visited[i]){
                    visited[i] = true;
                    bfs_ans[idx++] = i;
                    q.push(i);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; //무방향 간선
    }

    dfs_ans[0] = bfs_ans[0] = v;
    visited[v] = true; //시작 노드느 이미 방문
    dfs(v);

    memset(visited, false, sizeof(visited));
    visited[v] = true;
    idx = 1;
    bfs(v);

    for (int i = 0; i < n; i++){
        if(dfs_ans[i] == 0){
            break;
        }
        else{
            cout << dfs_ans[i] << " ";
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++){
        if(bfs_ans[i] == 0){
            break;
        }
        else{
            cout << bfs_ans[i] << " ";
        }
    }
}