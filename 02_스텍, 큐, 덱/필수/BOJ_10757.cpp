#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> bigNum(string a, string b)
{
    vector<int> ans;
    int idx_a = a.length() - 1;
    int idx_b = b.length() - 1;
    int sum, num, carry = 0;

    //작은 수 기준으로 덧셈
    while (idx_b >= 0)
    {
        sum = (a[idx_a] - '0') + (b[idx_b] - '0') + carry; //문자 -> 정수 변환 후 덧셈 | ex) 7 + 8 = 15
        num = sum % 10; // 15 % 10 = 5
        ans.push_back(num);
        carry = sum / 10; // 15 / 10 = 0
        idx_a--;
        idx_b--;
    }

    // 더 큰 수에 남은 숫자들 그대로 넣기
    while (idx_a >= 0){
        
        sum = a[idx_a] - '0' + carry;
        num = sum % 10;
        ans.push_back(num);
        carry = sum / 10;
        idx_a--;
    }

    //올림 수가 남아있다면 넣기
    if (carry > 0) ans.push_back(carry);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    //입력
    string a, b;
    cin >> a >> b;
    
    //연산
    if (a.length() < b.length()) //a가 큰수가 되도록
        swap(a, b);

    vector<int> result = bigNum(a, b);

    // 출력
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}