#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> card;
int binarySearch(int target){
    int left = 0;
    int right = n - 1;
    int mid, ans;

    while (left <= right){
        mid = (left + right) / 2;

        if (card[mid] == target){
            ans = 1;
            return ans;
        }

        if (card[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    ans = 0;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans;
    //입력
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    sort(card.begin(), card.end());

    //연산 && 출력
    cin >> m;
    while(m--){
        int input;
        cin >> input;
        ans = binarySearch(input);
        cout << ans << " ";
    }

}