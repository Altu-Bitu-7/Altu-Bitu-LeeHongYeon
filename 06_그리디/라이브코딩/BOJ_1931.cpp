#include <iostream>
#include <vector>
#include <algorithm>

typedef pair<int, int> pi;

using namespace std;

int main(){
    
    int n, cnt = 0;
    vector<pi> v;

    //입력
    cin >> n;
    v.assign(n, {0, 0});

    for (int i = 0; i < n; i++){
        cin >> v[i].second >> v[i].first; //끝나는 시간을 기준으로 봐야하므로 첫번째 요소에 끝나는 시간을, 두번째 요소에 시작시간을 담는다
    }

    //연산
    sort(v.begin(), v.end()); //first 기준으로 오름차순 정렬

    int finish_time = 0; //끝나는 시간을 저장할 변수
    for (int i = 0; i < n; i++){
        if(finish_time > v[i].second) {//끝나는 시간보다 회의가 먼저 시작하면 넘어가기
            continue;
        }

        cnt++;
        finish_time = v[i].first; //끝나는 시간 갱신
    }

    //출력
    cout << cnt;
}