#include <bits/stdc++.h> //iostream, vector, 알고리즘 한번에 불러옴

using namespace std;

deque<int> doDeck;
deque<int> suDeck;
deque<int> doGround;
deque<int> suGround;

//덱이 비어있는지 체크
bool isEmpty(){
    if (doDeck.empty() || suDeck.empty()){
        return true;
    }
    return false;
}

//종을 치는지 체크
void checkGround()
{
    // 그라운드의 합이 5가 되는 경우 - 수연이 종치기
    if (!doGround.empty() && !suGround.empty() && doGround.front() + suGround.front() == 5)
    {   
        //그라운드의 카드 뒤집에서 덱에 넣기
        while(!doGround.empty()){
            suDeck.push_back(doGround.back());
            doGround.pop_back();
        }
        while (!suGround.empty()){
            suDeck.push_back(suGround.back());
            suGround.pop_back();
        }
    }

    // 그라운드 가장 위에 있는 카드가 5인 경우 - 도도가 종치기
    if ((!doGround.empty() && doGround.front() == 5) || (!suGround.empty() && suGround.front() == 5))
    {
        //그라운드의 카드 뒤집에서 덱에 넣기
        while(!suGround.empty()){
            doDeck.push_back(suGround.back());
            suGround.pop_back();
        }
        while (!doGround.empty()){
            doDeck.push_back(doGround.back());
            doGround.pop_back();
        }
    }
    
}

string halliGalli(int m){
    bool isTurn = 1; //1이면 도도 차례, 0이면 수연 차례
    for (int i = 0; i < m; i++)
    {
        // 도도가 그라운드에 카드를 놓음
        if (isTurn){
            doGround.push_front(doDeck.front());
            doDeck.pop_front();
            if(isEmpty()){
                break;
            }
            checkGround();
            isTurn = 0;
            continue;
        }
        // 수연이가 그라운드에 카드를 놓음
        else{
            suGround.push_front(suDeck.front());
            suDeck.pop_front();
            if(isEmpty()){
                break;
            }
            checkGround();
            isTurn = 1;
            continue;
        }
    }

    if (suDeck.size() > doDeck.size()){
        return "su";
    }
    else if (suDeck.size() < doDeck.size()){
        return "do";
    }
    else{
        return "dosu";
    }

}

int main()
{
    int n, m;
    int input;

    // 입력
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        doDeck.push_front(input);
        cin >> input;
        suDeck.push_front(input);
    }

    // 연산 & 출력
    cout << halliGalli(m);
}