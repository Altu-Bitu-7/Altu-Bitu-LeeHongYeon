#include <iostream>

using namespace std;
// 10^3 ~= 2^10
// 10^7 ~= 2^25
const int MAX = 25;

int countBottle(int n)
{
    // n을 이진수로 나타냈을 때 1의 개수 세기(==필요한 물병의 최소개수)
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (n & (1 << i)) { //1을 <<를 25번 시키면 2의 25승만큼 커짐
                cnt++;
            }
    }

    return cnt;
}

int solution(int n, int k)
{
    int answer = 0; //상점에서 사야하는 물병의 수
    while (true){
        if(countBottle(n + answer) <= k)
        {
            return answer;
        }
        answer++;
    }

    return answer;
}

int main()
{   
    //입력
    int n, k;
    cin >> n >> k;

    //연산
    int answer = solution(n, k);

    //출력
    cout << answer;

}