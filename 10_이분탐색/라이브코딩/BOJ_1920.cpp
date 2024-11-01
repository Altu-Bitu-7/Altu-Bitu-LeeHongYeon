#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySeach(int n, int key, vector<int> nums){
    int left = 0; //첫번째를 가리키는 포인터
    int right = n - 1;  //마지막을 가리키는 포인터
    int mid;

    while (left <= right){
        mid = (left + right) / 2;

        //만약 mid값이 taregt값과 같다면
        if(nums[mid] == key){
            return 1;
        }
        //만약 mid값이 target보다 크면 더 작은 값을 탐색
        else if (nums[mid] > key){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    int n, m, key;
    //입력
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    cin >> m;
    while(m--){
        cin >> key;
        //cout << binarySeach(n, key, nums);
        cout << binary_search(nums.beging(), nums.end());
    }

    return 0;
}