#include <bits/stdc++.h>
#define INF (int)1e9

using namespace std;

typedef pair<int, int> pii;

int n, m, x;
vector<vector<pii>> start_graph, end_graph;
vector<int> start_dist, end_dist;

// 다익스트라 알고리즘
void dijkstra(vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) {
            continue;
        }

        for (auto& elem : graph[cur_pos]) {
            auto [edge_dist, nx_pos] = elem;  // 간선 거리와 다음 노드
            int nx_dist = cur_dist + edge_dist;  // 현재 거리 + 간선 거리
            if (nx_dist < dist[nx_pos]) {
                dist[nx_pos] = nx_dist;
                pq.push({nx_dist, nx_pos});
            }
        }
    }
}

// 왕복 거리 계산
int solution() {
    int max_dist = -1;
    dijkstra(start_graph, start_dist);  // 시작점에서 모든 노드로
    dijkstra(end_graph, end_dist);     // 모든 노드에서 시작점으로

    for (int i = 1; i <= n; i++) {
        if (start_dist[i] == INF || end_dist[i] == INF) continue;  // 갈 수 없는 경우 제외
        max_dist = max(max_dist, start_dist[i] + end_dist[i]);
    }
    return max_dist;
}

int main() {
    int from, to, dist;
    // 입력
    cin >> n >> m >> x;
    start_graph.resize(n + 1);
    end_graph.resize(n + 1);
    start_dist.resize(n + 1, INF);
    end_dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dist;
        start_graph[from].push_back({dist, to});
        end_graph[to].push_back({dist, from});
    }

    // 연산 & 출력
    cout << solution();
}
