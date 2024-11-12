#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 100002

using namespace std;

int solution(int n, int k, vector<int>& sequence){
    int left = 0;
    int right = 0;
    int ans = -1;
    vector<int> checked (MAXSIZE, 0);

    for (; left < n; left++){
        while(right < n && checked[sequence[right]] < k){
            checked[sequence[right]]++;
            right++;
        }
        ans = max(ans, right - left);
        if(right == n){
            break;
        }
        checked[sequence[left]]--;
    }
    return ans;
}

int main(){
    int n, k;
    vector<int> sequence;
    //입력
    cin >> n >> k;
    sequence.resize(n);

    for (int i = 0; i < n; i++){
        cin >> sequence[i];
    }

    //연산 & 출력
    cout << solution(n, k, sequence);
}