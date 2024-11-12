#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;
vector<int> length;

int binanySearch(){
    int left = 1;
    int right = length[n - 1];
    int mid, ans;

    while (left <= right){
        mid = (left + right) / 2;
        int now = 0;

        for (int i = 0; i < n; i++){
            now += length[i] / mid;
        }

        if (now >= m){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //입력
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        length.push_back(tmp);
    }
    //연산&&출력
    sort(length.begin(), length.end());
    cout << binanySearch();
}