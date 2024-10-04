#include <iostream>
#include <vector>

using namespace std;

int main(){

    //입력
    int n;
    vector<int> lost;
    vector<int> reserve;

    //연산
    int answer = 0;
    vector<int> clothes_cnt(n+1, 0); //인덱스가 1부터 시작하므로 n+1 사이즈로 잡아야함

    for (int i = 0; i < lost.size(); i++){
        clothes_cnt[lost[i]]--;
    }

    for (int i = 0; i < reserve.size(); i++){
        clothes_cnt[reserve[i]]++;
    }

    for (int i = 0; i < n; i++){
        if(clothes_cnt[i]){ //옷이 있으면 넘어가기
            continue;
        }
        //옷이 없을 경우
        //옷이 없는 학생의 바로 앞의 학생이 여벌 옷이 있으면 나눠주기
        if(clothes_cnt[i-1] == 2){
            clothes_cnt[i]++; //옷이 없는 학생은 옷이 1이 되고
            clothes_cnt[i-1]--; //여벌 옷이 있는 학생도 옷이 1이 됨
        }
        
        //옷이 없는 학생의 바로 뒤의 학생이 여벌 옷이 있으면 나눠주기
        else if (clothes_cnt[i+1] == 2){
            clothes_cnt[i]++;
            clothes_cnt[i+1]--;
        }
    }

    for (int i = 0; i < n; i++){
        if(clothes_cnt[i]){
            answer++;
        }
    }

    //출력
    cout << answer;
}