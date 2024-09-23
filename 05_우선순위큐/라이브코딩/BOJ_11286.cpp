#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const int& x1, const int& x2){
        if (abs(x1) == abs(x2)){ //절대값이 같으면
            return x1 > x2; //실제로 더 작은 값 리턴
        }
        return abs(x1) > abs(x2);
    }
};   

int main(){

    int n, x;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;
    
    while(n--){
        cin >> x;

        //x가 0이라면 최대 힙에서 가장 큰 값 출력하고 제거
        if (x == 0){
            //최대 힙이 비었다면 0출력
            if(pq.empty()){
                cout << "0\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        //x가 자연수라면 최대 힙에 추가
        else{
            pq.push(x);
        }
    }
}