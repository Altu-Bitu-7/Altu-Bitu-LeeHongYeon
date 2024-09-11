#include <iostream>

using namespace std;

int solution(int n){
    for (int i = 1; i < n; i++) //i는 생성자, 생성자는 분해합 n보다 항상 작음
    {
        int sum = i; //생성자
        int tmp = i; //자릿수
        while (tmp){ //tmp != 0
            sum += tmp % 10; //생성자 + 자릿수 = 분해합
            tmp /= 10;
        }

        if (sum == n){
            return i;
        }
    }

    return 0; //생성자를 못 찾은 경우
}

int main(){
    //입력
    int n;
    cin >> n;

    //연산 & 출력
    cout << solution(n);

}