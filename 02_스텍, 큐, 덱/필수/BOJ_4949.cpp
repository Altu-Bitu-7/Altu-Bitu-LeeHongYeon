#include <iostream>
#include <stack>

using namespace std;

bool isEmpty(string bracket)
{
    stack<char> s;
    for (char c : bracket){
        
        //여는 괄호는 무조건 넣기
        if (c == '(' || c == '[') 
            s.push(c);
        
        //닫는 괄호가 들어왔을 경우
        if (c == ')'){ 
            if (s.empty() || s.top() != '(') //스택이 비어있거나 짝이 맞지 않으면 false 리턴 *스택이 비어있을 때 top을 호출시 런타임 에러 발생하니 반드시 empty()가 먼저 호출되도록 해야함
                return false;
            s.pop();
        }

        if (c == ']'){
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string str;

    // 입력
    while (true)
    {
        //문장을 \n을 기준으로 받아옴
        getline(cin, str);
        if (str == ".") break; //.하나만 들어왔을 때 입력 종료

        // 연산 & 출력
        if (isEmpty(str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}