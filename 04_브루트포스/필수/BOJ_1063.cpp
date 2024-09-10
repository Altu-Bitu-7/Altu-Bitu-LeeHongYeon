#include <iostream>
#include <vector>

using namespace std;

void solution(int m)
{

    string cmd;
    int x;
    vector<bool> s(21, false);

    while (m--)
    {
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            s[x] = true;
        }

        else if (cmd == "remove")
        {
            cin >> x;
            if (s[x])
            {
                s[x] = false;
            }
        }

        else if (cmd == "check")
        {
            cin >> x;
            cout << s[x] << "\n";
        }

        else if (cmd == "toggle")
        {
            cin >> x;
            if (s[x])
            {
                s[x] = false;
            }
            else
            {
                s[x] = true;
            }
        }

        else if (cmd == "all")
        {
            fill(s.begin(), s.end(), true);
        }

        else if (cmd == "empty")
        {
            fill(s.begin(), s.end(), false);
        }
    }
}

int main()
{
    // 입출력 속도를 증가시키는 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력
    int m;
    cin >> m;

    // 연산 & 출력
    solution(m);
}