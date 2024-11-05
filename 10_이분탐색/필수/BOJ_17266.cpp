#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> position;

bool findHeight(int height) {
    if (position[0] - height > 0) {
        return false;
    }

    for (int i = 1; i < m; i++) {
        if (position[i] - height > position[i - 1] + height) {
            return false;
        }
    }

    if (position[m - 1] + height < n){
        return false;
    }
    return true;
}

int binarySearch() {
    int left = 0;
    int right = n;
    int mid, ans = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (findHeight(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    // 입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        position.push_back(input);
    }

    // 연산 && 출력
    cout << binarySearch();

    return 0;
}
