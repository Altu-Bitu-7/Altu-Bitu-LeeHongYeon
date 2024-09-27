#include <bits/stdc++.h> //iostream, vector, 알고리즘 한번에 불러옴

using namespace std;

typedef pair<int, int> pi;

int topDownDp(vector<pi>& counsel, int n){
    vector<int> dp(n+1, 0);

    for (int i = n-1; i >= 0; i--){
        if (i + counsel[i].first > n){
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i], dp[i + counsel[i].first] + counsel[i].second);
        }
    }

    return dp[0];
}

int bottomUpDp(vector<pi>& counsel, int n){
    vector<int> dp(n+1);

    for (int i = 0; i < n; i++){
        for (int j = i + counsel[i].first; j <= n; j++){
            dp[j] = max(dp[i] + counsel[i].second, dp[j]);
        }
    }

    return dp[n];
}


int main(){
    int n;
    vector<pi> counsel(n, {0, 0});

    //입력
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> counsel[i].first >> counsel[i].second;
    }

    //연산 & 출력
    cout << bottomUpDp(counsel, n);
}