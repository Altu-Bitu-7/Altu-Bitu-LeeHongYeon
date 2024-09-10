#include <iostream>
#include<vector>

using namespace std;

typedef pair<char, int> pos;

pos move(pos p, string cmd){

    if (cmd == "R"){
        p.first++;
    }
    else if (cmd == "L"){
        p.first--;
    }
    else if (cmd == "B"){
        p.second--;
    }
    else if (cmd == "T"){
        p.second++;
    }
    else if (cmd == "RT"){
        p.first++;
        p.second++;
    }
    else if (cmd == "LT"){
        p.first--;
        p.second++;
    }
    else if (cmd == "RB"){
        p.first++;
        p.second--;
    }
    else if (cmd == "LB"){
        p.first--;
        p.second--;
    }

    return p;
}

pos checkStone(pos stone, pos king, string cmd){
    if (stone.first == king.first && stone.second == king.second){ //돌과 킹의 위치가 같아지면
        return move(stone, cmd); //돌을 킹과 같은 방향으로 이동
    }
    return stone; //아니라면 돌 위치 그대로
}

bool isInRange(pos p){
    if (p.first < 'A' || p.second > 'H' || p.second < 1 || p.second > 8){ //체스판 벗어나는지 체크
        return false;
    }
    return true;
}

int main(){
    //입력
    pos king, stone;
    int n;

    cin >> king.first >> king.second;
    cin >> stone.first >> stone.second;
    cin >> n;

    string cmd;

    //연산
    while (n--){
        cin >> cmd;
        pos move_king = move(king, cmd);
        pos move_stone = checkStone(stone, move_king, cmd);

        if (isInRange(move_king) && isInRange(move_stone)){
            king = move_king;
            stone = move_stone;
        }
    }

    //출력
    cout << king.first << king.second << "\n";
    cout << stone.first << stone.second;
}