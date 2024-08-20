#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
//일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
// | 일일 에너지 섭취량 - 일일 에너지 소비량 | > T ->
//일일 기초대사량 += (일일 에너지 섭취량 - 일일 에너지 소비량) / 2

void noBMRChange(int weight, int BMR, int day, int d_intake, int d_active){
    
    weight += (d_intake - (BMR + d_active)) * day;

    if (weight <= 0)
        cout << "Danger Diet" << '\n';
    else
        cout << weight << " " << BMR << '\n';

}

void yesBMRChange(int weight, int BMR, int T, int day, int d_intake, int d_active, int i_intake){

    for (int i = 0; i < day; i++)
    {
        weight += (d_intake - (BMR + d_active));
        if (abs(d_intake - (BMR + d_active)) > T)
            BMR += float(d_intake - (BMR + d_active)) / 2.0;
    }

    if (weight <= 0 || BMR <= 0)
        cout << "Danger Diet" << '\n';

    else
    {
        cout << weight << " " << BMR << " ";

        if (i_intake - BMR > 0)
            cout << "YOYO";

        else
            cout << "NO";
    }
    
}


int main(){

    //입력
    int weight, BMR, T; //전 체중, 전 일일 기초 대사량, 역치 
    int day, d_intake, d_active;  // 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량

    cin >> weight >> BMR >> T;
    cin >> day >> d_intake >> d_active;
    int i_intake = BMR; //다이어트 전 일일 에너지 섭취량 = 전 일일 기초 대사량

    //연산 & 출력
    noBMRChange(weight, BMR, day, d_intake, d_active);
    yesBMRChange(weight, BMR, T, day, d_intake, d_active, i_intake);

}