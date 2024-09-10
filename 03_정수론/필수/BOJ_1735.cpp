#include <iostream>
#include <algorithm>

using namespace std;

int findGcd(int a, int b)
{
    while (b){// b == 0 이되면 반복문 탈출
        a %= b; // a = a%b
        swap(a, b); // a > b
    }
    return a;
}

void add(int n1, int m1, int n2, int m2)
{
    int m3 = m1 * m2; //공통 분모
    int n3 = n1 * m2 + n2 * m1; //통분 후 더한 분수의 분자

    int gcd = findGcd(max(m3, n3), min(m3, n3));

    if (gcd != 1) //gcd가 1일 경우 이미 기약 분수임
    {
        m3 /= gcd;
        n3 /= gcd;
    }
    
    cout << n3 << " " << m3;
}

//최대공약수로 분자, 분모를 나누어주면 기약 분수를 얻을 수 있다

int main(){
    //입력
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    //연산 & 출력
    add(n1, m1, n2, m2);
}
