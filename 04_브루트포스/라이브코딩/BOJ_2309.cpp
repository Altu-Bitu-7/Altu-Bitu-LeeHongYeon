#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 9; //난쟁이 수 9명은 계속 사용되니 상수화

void solution (vector<int> &arr){
    //9명의 키의 합
    int sum = 0;
    for (int i = 0; i < CNT; i++){
        sum += arr[i];
    }
    //2명을 제외했을 때 100이 되는지 확인
    for (int i = 0; i < CNT; i++){
        for (int j = i + 1; j < CNT; j++){ //2명 씩 비교하니 j는 i 다음 사람
            if (sum - arr[i] - arr[j] == 100){ //첫번째 난쟁이와 두번째 난쟁이를 뺏을 때
                //j 먼저 지워야 인덱스가 밀리지 않음 (뒤에서 먼저 제거)
                arr.erase(arr.begin() + j); //j번째 난쟁이 삭제
                arr.erase(arr.begin() + i); //i번째 난쟁이 삭제
                return;
            }
        }
    }

}

int main(){
    //입력
    vector<int> arr(CNT); //크기 9
    for (int i = 0; i < CNT; i++){
        cin >> arr[i];
    }

    //연산
    solution(arr);
    sort(arr.begin(), arr.end()); //오름차순 정렬

    //출력
    for (auto it : arr){
        cout << it << "\n";
    }
}