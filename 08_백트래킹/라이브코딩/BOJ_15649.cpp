#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 8;

//재귀함수의 과부하를 막기 위해 전역변수 사용
int n, m; 
vector<int> sequence(8);
vector<bool> is_used(8);

void printSequence(){
    for (int i = 0; i < m; i++){
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int count){
    //기저조건
    if (count == m){
        printSequence();
        return;
    }
    
    for (int i = 1; i <= n; i++){
        if(is_used[i]){
            continue;
        }
        is_used[i] = true;
        sequence[count] = i;
        backtrack(count + 1);
        is_used[i] = false;
    }
}

int main(){
    //입력
    cin >> n >> m;
    //연산 & 출력
    backtrack(0); //매개변수 0은 수열에 들어있는 수의 개수
}