#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 15;

int n, ans;
vector<bool> is_queen_in_col[MAX_SIZE];
vector<bool> is_queen_in_left[MAX_SIZE * 2]; //좌방향 대각선
vector<bool> is_queen_in_right[MAX_SIZE * 2]; //우방향 대각선

void backtrack(int row){
    //기저조건
    if(row == n){
        ans++;
        return;
    }
    
    for (int col = 0; col < n; col++){
        if(!is_queen_in_col[col] && !is_queen_in_left[row + col] &&!is_queen_in_right[row - col + n]){
            is_queen_in_col[col] = true;
            is_queen_in_left[row + col] = true;
            is_queen_in_right[row - col + n] = true; //양수를 보장하기 위해 n을 더함

            backtrack(row + 1);

            is_queen_in_col[col] = false;
            is_queen_in_left[row + col] = false;
            is_queen_in_right[row - col + n] = false;
        }
    }
}

int main(){
    //인력
    cin >> n;

    //연산
    backtrack(0);

    //출력
    cout << ans;
}