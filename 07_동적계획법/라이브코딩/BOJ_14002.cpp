#include <bits/stdc++.h> //iostream, vector, 알고리즘 한번에 불러옴

using namespace std;

vector<int> setDp(vector<int>& arr, int n){
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp;
}

vector<int> makeLis(vector<int>& arr, int n){
    vector<int> dp = setDp(arr, n);
    vector<int> ans;

    int len = -1;
    for (int i = 0; i < n; i++){
        len = max(len, dp[i]);
    }

    for (int i = n - 1; i >= 0; i--){
        if(dp[i] == len){
            ans.push_back(arr[i]);
            len--;
        }
    }

    return ans;
}

int main(){
    int n;
    vector<int> arr(n, 0);
    vector<int> ans;
    //입력
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //연산
    ans = makeLis(arr, n);

    //출력
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << "\n";
    }

}