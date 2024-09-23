#include <iostream>
#include <vector>

using namespace std;

//vi가 최대 10^9까지 가능하니 오버플로우 방지를 위해 long long 타입 이용
long long getSpeed(vector<int>& v){
    long long v_min = 0;
    for (int i = v.size() - 1; i >= 0; i--){
        if (v_min < v[i]){
            v_min = v[i];
        }
        else{
            if (v_min%v[i] == 0){
                continue;
            }
            v_min = (v_min/v[i] + 1) * v[i];
        }
    }
    return v_min;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long ans;
    //입력
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    //연산
    ans = getSpeed(v);
    
    //출력
    cout << ans;
}
