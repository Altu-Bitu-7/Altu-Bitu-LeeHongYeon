#include <iostream>
#include <vector>

using namespace std;

string fortuneWheel(int n, int k)
{   
    vector<char> wheel(n, '?'); //바퀴의 모든 칸을 ?로 초기화
    int pointer = 0; // 화살표
    string ans = "";
    int s;
    char c;

    while (k--)
    {
        cin >> s >> c;
        pointer = (pointer + s) % n; // 바퀴 회전 후 화살표가 가리키는 곳

        // 똑같이 돌려서 같은 칸이 나온 경우 채울 필요x
        if (wheel[pointer] == c){
            continue;
        }

        // 해당 칸에 이미 다른 글자가 있을 경우
        if (wheel[pointer] != '?'){
            return "!";
        }

        // 다른 칸에 있는 글자들이 같을 경우
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (wheel[i] != '?' && wheel[i] == wheel[j]){ // ?는 여러 칸에 존재할 수 있음
                    return "!";
                }
            }
        }

        wheel[pointer] = c;
    }

    for (int i = pointer + n; i > pointer; i--){
        ans += wheel[i % n];
    }

    return ans;
    
}

int main()
{
    // 입력
    int n, k, s;
    char c;
    cin >> n >> k;

    // 연산
    string ans = fortuneWheel(n, k);

    //출력
    cout << ans;
}