#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//lower bound
int lowerBound(int left, int right, int target, vector<int> nums){
    while (left <= right){
        int mid = (left + right) / 2;
        //중간값이 target보다 크다면 target은 더 왼쪽에 있음
        //중간값이 traget보다 같다면 target이 왼쪽에 더 있을 수도 있었을
        //왼쪽 구석 탐색
        if(nums[mid] >= target){
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }returm left;

    }
}

//upper bound
int //lower bound
int lowerBound(int left, int right, int target, vector<int> nums){
    while (left <= right){
        int mid = (left + right) / 2;
        //중간값이 target보다 크다면 target은 더 왼쪽에 있음
        //중간값이 traget보다 같다면 target이 왼쪽에 더 있을 수도 있었을
        //왼쪽 구석 탐색
        if(nums[mid] >= target){
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }returm left;

    }
}Bound(int left, int right, int target, vector<int> nums){
    while (left <= right){
        int mid = (left + right) / 2;
        //중간값이 target보다 크다면 target은 더 왼쪽에 있음
        //중간값이 traget보다 같다면 target이 왼쪽에 더 있을 수도 있었을
        //왼쪽 구석 탐색
        if(nums[mid] >= target){
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }returm left;

    }
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
    }

    return 0;
}