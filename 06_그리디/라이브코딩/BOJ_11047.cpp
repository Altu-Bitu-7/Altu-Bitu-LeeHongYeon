#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n, k, cnt;
    vector<int> coin;

    //입력
    cin >> n >> k;
    coin.assign(n, 0); //벡터 사이즈 n으로 초기화

    for (int i = 0; i < n; i++){
        cin >> coin[i];
    }

    //연산
    //가치가 큰 동전부터 사용하려면 인덱스는 -1부터 사용
    while (n--){
        cnt += k/coin[n];
        k %= coin[n];
    }

    //출력
    cout << cnt;
}