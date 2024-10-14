#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> sequence(11);
vector<int> operators(4);

int maxRes = -1000000001;
int minRes = 1000000001;

void checkMaxMin(int result){
    if(result > maxRes){
        maxRes = result;
    }
    if (result < minRes){
        minRes = result;
    }
}

void backtrack(int count, int result){
    //기저조건
    if (count == n){
        checkMaxMin(result);
        return;
    }

    for (int i = 0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0){ //+ 기호 일경우
                backtrack(count + 1, result + sequence[count]);
            }
            else if (i == 1){//- 기호 일경우
                backtrack(count + 1, result - sequence[count]);
            }
            else if (i == 2){//x 기호 일경우
                backtrack(count + 1, result * sequence[count]);
            }
            else{ // 나눗셈 기호 일경우
                backtrack(count + 1, result / sequence[count]);
            }
            operators[i]++;
        }
    }
}

int main(){
    //입력
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> sequence[i];
    }

    for (int i = 0; i < 4; i++){
        cin >> operators[i];
    }

    //연산
    backtrack(1, sequence[0]);

    //출력
    cout << maxRes << "\n" << minRes;
}