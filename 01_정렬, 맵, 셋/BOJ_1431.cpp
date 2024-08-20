#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s){
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i]))
            sum += s[i] - '0';
    }

    return sum;
}


bool cmp(const string& s1, const string& s2){

    if (s1.size() != s2.size()) //길이가 다르면 짧은 것 먼저 (오름차순)
        return  s1.size() < s2.size(); //만약 s1이 s2보다 짧다면 true -> 오름차순, 길다면 false -> s1과 s2 swap -> 오름차순
    
    if (sum(s1) != sum(s2)) //숫자들의 합이 더 적은 것 먼저
        return sum(s1) < sum(s2); //오름차순
    
    return s1 < s2; //사전순 비교

}

int main(){
    int n;
    
    //입력
    cin >> n;
    vector<string> serial(n);

    for (int i = 0; i < n; i++){
        cin >> serial[i];
    }

    //연산

    sort(serial.begin(), serial.end(), cmp); //cmp가 false return시 swap

    //출력

    for (int i = 0; i < n; i++){
        cout << serial[i] << '\n';
    }

    return 0;
}