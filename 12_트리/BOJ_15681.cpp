#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> node;

int dfs(int parent, int cur){
    int count = 0;

    for (int next : edge[cur]){

        if(next == parent){
            continue;
        }
        count += dfs(cur, next);
    }
    node[cur] = count + 1;
    return node[cur];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q;

    //입력
    cin >> n >> r >> q;
    edge.resize(n + 1);
    node.resize(n + 1);

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    //연산
    dfs(0, r);
    
    //출력
    for (int i = 0; i < q; i++){
        int u;
        cin >> u;

        cout << node[u] << "\n";
    }
}