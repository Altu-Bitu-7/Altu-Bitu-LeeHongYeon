#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

void solution(int left, int right){
    if(left >= right){
        return;
    }
    int root = tree[left];
    int flag = left + 1;

    while (flag < right){
        if(root < tree[flag]){
            break;
        }
        flag++;
    }

    solution(left + 1, flag);
    solution(flag, right);

    cout << root << "\n";
}

int main(){
    int n;
    //입력
    while (cin >> n){
        tree.push_back(n);
    }
    //연산 & 출력
    solution(0, tree.size());
}