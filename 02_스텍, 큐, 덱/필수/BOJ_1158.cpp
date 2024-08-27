#include <iostream>
#include <queue>

using namespace std;

vector<int> solving (int n, int k){

    queue<int> q; //큐 선언
    vector<int> v; //요세푸스 순열이 들어갈 벡터 선언

    //원에 숫자 집어넣기
    for (int i = 1; i <= n; i++){
        q.push(i);
    }

    while (n--){

        //k-1번까지의 원소들을 뒤로 이동
        for (int i = 0; i < k - 1; i++){
            q.push(q.front()); //ex) 1 2 3 4 5 6 7 -> 3 4 5 6 7 1 2
            q.pop();
        }

        //k번째 원소를 요세푸스 순열에 집어넣음
        v.push_back(q.front());
        q.pop(); //ex) q : 4 5 6 7 1 2 | v: 3
    }

    return v;
}

int main(){

    vector<int> ans;

    //입력
    int n, k; //큐의 크기, 삭제할 번호
    cin >> n >> k;

    //연산
    ans = solving(n, k);


    //출력
    cout << '<' << ans[0];
    for (int i = 1; i < n; i++){
        cout << ", " << ans[i];
    }
    cout << '>';
}