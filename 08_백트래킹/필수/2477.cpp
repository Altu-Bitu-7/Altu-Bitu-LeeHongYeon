#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> dir_len;

int findArea(vector<dir_len>& area){
    int bigSquare = 0;
    int smallSquare;
    int maxIdx;
    
    for (int i = 0; i < 6; i++){
        if (bigSquare < area[i].second * area[(i + 1) % 6].second){ //인덱스 오버플로우 방지
            bigSquare = area[i].second * area[(i + 1) % 6].second; //긴 변들을 입력에서 연속되게 등장함
            maxIdx = i; //긴 변의 등장한 인덱스 저장
        }
    }
    
    //긴 변의 등장한 후 3칸, 4칸 뒤에 작은 사각형의 가로, 세로 길이가 나옴, 인덱스 오버플로우 방지를 위해 %6
    smallSquare = area[(maxIdx + 3) % 6].second * area[(maxIdx + 4) % 6].second;

    return bigSquare - smallSquare;
}

int main(){
    int k;
    vector<dir_len> area(6);
    int ans;

    //입력
    cin >> k;
    for (int i = 0; i < 6; i++){
        cin >> area[i].first >> area[i].second;
    }

    //연산
    ans = findArea(area);

    //출력
    cout << k * ans;
}

