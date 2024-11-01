#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가장 인접한 두 공유기 사이의 거리가 dist일 때, 놓을 수 있는 최대 공유기의 개수
int cntRouter(int dist, vecotr<int> &house){
    int cnt = 1;
    int cur = house[0];

    for (int i = 0; i < house.size(); i++){
        if(house[i] - cur >= dist){
            cnt++;
            cur = house[i];
        }
    }
    return cnt;
}

int binarySearch(int left, int right, int target, vecotr<int> house){
    while(left <= right){
        //가장 인접한 두 공유기 사이의 거리가 mid
        int mid = (left + right) / 2;
        //설치할 수 있는 최대 공유기의 개수
        int installed = cntRouter(mid, house);

        if(installed < target){
            right = mid -1;
        }
        else { //설치할 수 있는 공유기의 수가 타켓보다 크면 -> 거리를 늘려보자
            left = mid + 1;
        }

    }
    return left - 1;
}

int main(){
    int n, c;
    //입력
    cin >> n >> c;
    vector<int> house(n);
    for (int i = 0; i < n; i++){
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    cout << binarySearch(1, house.end() - house.begin());
    return 0;
}