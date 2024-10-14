#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//재귀함수의 과부하를 막기 위해 전역변수 사용
int n, m; 
vector<int> sequence(7);
vector<bool> is_used(7);
vector<int> nSet;

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

    for (int i : nSet){
        sequence[count] = i;
        backtrack(count + 1);
    }


}

int main(){
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(is_used[tmp]){
            continue;
        }
        is_used[tmp] = true;
        nSet.push_back(tmp);
    }

    //연산
    sort(nSet.begin(), nSet.end());
    backtrack(0);
}
