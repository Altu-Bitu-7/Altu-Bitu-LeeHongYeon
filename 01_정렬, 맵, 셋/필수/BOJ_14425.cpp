#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){

    //입출력 속도를 증가시키는 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int count = 0;
    string input;
    set<string> s;

    //입력&연산

    cin >> n >> m;
    
    //집합 s에 들어갈 n개의 문자열 입력 받기
    for (int i = 0; i < n; i++){
        cin >> input;
        s.insert(input);
    }

    //m개의 문자열을 집합 s에 있는 문자열들과 하나씩 비교하기 -> 시간 초과
    // for (int i = 0; i < m; i++){
    //     cin >> input;
    //     for (auto iter = s.begin(); iter != s.end(); iter++){
    //         if (*iter == input) count++;
    //     }
    // }

    for (int i = 0; i < m; i++){
        cin >> input;
        if (s.find(input) != s.end()) //find함수는 원소가 가리키는 반복자를 반환, 없으면  s.end() 반복자 반환
            count++;
    }

    cout << count;

    return 0;
}