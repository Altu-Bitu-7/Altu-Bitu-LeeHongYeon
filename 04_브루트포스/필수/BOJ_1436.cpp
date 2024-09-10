#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getMovieName(int n)
{
    int cnt = 665;
    string name;
    while (n > 0)
    {
        cnt++;
        name = to_string(cnt);
        if (name.find("666") != string::npos)
        {
            n--;
        }
    }

    return cnt;
}

int main()
{

    int name;
    // 입력
    int n;
    cin >> n;

    // 연산
    name = getMovieName(n);

    // 출력
    cout << name;
}