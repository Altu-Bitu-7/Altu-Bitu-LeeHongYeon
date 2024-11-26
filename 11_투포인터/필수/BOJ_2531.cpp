#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int solution(int n, int k, int c, vector<int>& sushi){
    bool is_visited[3001] = {false, };
    int flag, coupon, max_dish = 0;

    for (int i = 0; i < n; i++){
        flag = 0;
        coupon = 1;
        for (int j = i; j < i + k; j++){
            if(is_visited[sushi[j % n]]){
                flag++;
            }
            else{
                is_visited[sushi[j % n]] = true;
            }
            
            if (sushi[j % n] == c){
                coupon = 0;
            }
        }
        max_dish = max(max_dish, k - flag + coupon);
        memset(is_visited, false, sizeof(is_visited));
    }
    return max_dish;
}

int main(){
    int n, d, k, c;
    //입력
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i = 0; i < n; i++){
        cin >> sushi[i];
    }
    
    //연산 & 출력
    cout << solution(n, k, c, sushi);
}