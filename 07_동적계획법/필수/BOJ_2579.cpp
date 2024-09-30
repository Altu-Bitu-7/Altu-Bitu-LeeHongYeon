#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int>& stair){
    vector<int> dp(n+1, 0);
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 3] + stair[i] + stair[i - 1], dp[i - 2] + stair[i]);
    }

    return dp[n];
}

int main(){
    int n;
    vector<int> stair;

    //입력
    cin >> n;
    stair.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> stair[i];
    }

    //연산&출력
    cout << solution(n, stair);
    
}