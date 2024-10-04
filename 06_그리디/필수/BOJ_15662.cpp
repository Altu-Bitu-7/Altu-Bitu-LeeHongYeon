#include <iostream>
#include <vector>

#define MAX 1010

using namespace std;

typedef pair<int, int> cmd;
vector<int> v[MAX];
vector<cmd> commands;

void Turning(int idx, int direction){
    if (direction == 1){
        int tmp = v[idx].at(7);
        for (int i = 6; i>= 0; i--){
            v[idx].at(i + 1) = v[idx].at(i);
        }
        v[idx].at(0) = tmp;
    }
    else{
        int tmp = v[idx].at(0);
        for (int i = 1; i <= 7; i++){
            v[idx].at(i - 1) = v[idx].at(i);
        }
        v[idx].at(7) = tmp;
    }
}

void realTurning(vector<cmd>& turning){
    int idx;
    int direction;
    for (int i = 0; i < turning.size(); i++){
        idx = turning[i].first;
        direction = turning[i].second;
        Turning(idx, direction);
    }
}

int reverse(int current_direction){ 
    if (current_direction == 1) {
        return -1;
    }
    else{
        return 1;
    }
}

vector<cmd> findTuringWheel(int t, int idx, int direction){
    vector<cmd> r;
    r.push_back(make_pair(idx, direction));
    int side1 = v[idx].at(2);
    int side2;
    int current_direction = direction;

    for (int i = idx + 1; i <= t; i++){
        side2 = v[i].at(6);
        if (side1 != side2){
            r.push_back(make_pair(i, reverse(current_direction)));
            side1 = v[i].at(2);
            current_direction = reverse(current_direction);
        }
        else{
            break;
        }
    }

    side1 = v[idx].at(6);
    side2 = -1;
    current_direction = direction;
    for (int i = idx - 1; i >= 1; i--){
        side2 = v[i].at(2);
        if (side1 != side2){
            r.push_back(make_pair(i, reverse(current_direction)));
            side1 = v[i].at(6);
            current_direction = reverse(current_direction);
        }
        else{
            break;
        }
    }

    return r;
}

int solution(int t, int k){
    int idx, direction;
    vector<cmd> turing;
    for (int i  = 0; i < k; i++){
        idx = commands[i].first;
        direction = commands[i].second;
        turing = findTuringWheel(t, idx, direction);
        realTurning(turing);
    }

    int cnt = 0;
    for (int i = 1; i <= t; i++){
        if(v[i].at(0) == 1){
            cnt++;
        }
    }

    return cnt;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;
    int idx, direction;
    int ans;
    string s;

    //입력
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> s;
        for (int j = 0; j < s.length(); j++){
            v[i].push_back(s[j] - '0');
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> idx >> direction;
        commands.push_back(make_pair(idx, direction));
    }

    //연산
    ans = solution(t, k);

    //출력
    cout << ans;
}