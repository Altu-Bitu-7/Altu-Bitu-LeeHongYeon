#include <iostream>
#include <vector>

using namespace std;

string palindrome(char &mid, vector<int> &alphabet)
{
    string ans = "";
    string reverse = "";
    for (int i = 0; i < alphabet.size(); i++){
        if (alphabet[i] == 0){
            continue;
        }
        // 해당 알파벳의 절반 만큼만 넣기
        for (int j = 0; j < alphabet[i] / 2; j++){ 
            ans += (char)(i + 'A');
        }
    }

    for (int i = ans.length() - 1; i >= 0; i--){
        reverse += ans[i];
    }

    // 홀수 개의 문자가 있다면 가운데에 넣기
    if (mid != '!'){ 
        ans += mid;
    }
    ans += reverse;
    return ans;

}

bool haveManyOddChar(string name, char &mid, vector<int> &alphabet) // 홀수 개의 문자가 여러개 인지 확인하는 함수
{
    int cnt = 0;
    for (int i = 0; i < name.length(); i++)
    {
        alphabet[(int)(name.at(i) - 'A')]++;
    }

    for (int i = 0; i < alphabet.size(); i++)
    {
        // 문자가 홀수개 있다면
        if (alphabet[i] % 2 != 0)
        { 
            cnt++;
            mid = (char)(i + 'A');
            if (cnt > 1) //홀수개의 문자가 1개보다 많은 경우
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string name;
    string ans;
    char mid = '!';
    vector<int> alphabet(26, 0);

    // 입력
    cin >> name;

    // 연산 & 출력
    if (!haveManyOddChar(name, mid, alphabet))
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    ans = palindrome(mid, alphabet);
    cout << ans;
}