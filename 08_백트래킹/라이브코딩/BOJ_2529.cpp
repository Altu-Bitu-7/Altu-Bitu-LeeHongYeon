#include <iostream>
#include <vector>

using namespace std;

const int MAX_K = 9;

int k;
vector<char> symbols(MAX_K);
vector<bool> check(9);
vector<char> sequence; //앞에 0이 오는 경우 무시하여 출력하는 경우 방지
string max_sequence = "0";
string min_sequence = "999999999";

void updateAnswer(){
    string num = "";
    for (int i : sequence){
        num += to_string(i);
    }
    max_sequence = max(max_sequence, num);
    min_sequence = min(min_sequence, num);
}

void backtrack(int count){
    //기저 조건
    if(count == k + 1{
        updateAnswer();
        return;
    }

    for (int i = 0; i < 10; i++){
        if(check[i]){
            continue;
        }
        if(count == 0 || //처음 넣을 때
            symbols[count - 1] == ">" && sequence[count - 1] > i || //이전 숫자 > 현재숫자
            symbols[count - 1] == "<" && sequence[count - 1] < i){ //이전 숫자 < 현재숫자
            sequence.push_back(i);
            check[i] = true;
            backtrack(count + 1);
        }
        check[i] = false;
        sequence.pop_back();
    }

int main(){
    //입력
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> symbols[i];
    }

    //연산
    backtrack();

    //출력
    cout << max_sequence << "\n" << min_sequence;
}