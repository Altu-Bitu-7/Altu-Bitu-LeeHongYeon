#include <iostream>
#include <vector>

#define MAX 1000000 // 3부터 최대 100만까지의 수들 중 소수 판별 | 500만은 오버플로우 발생하니 주의...

using namespace std;

// 소수 배열 구하기
vector<bool> getPrimes()
{
    // true로 초기화 -> 각 인덱스의 값이 true이면 그 인덱스에 해당하는 숫자는 소수
    // false이면 그 인덱스에 해당하는 숫자는 소수가 아님
    vector<bool> primes(MAX + 1, true);
    for (int i = 2; i * i <= MAX; i++) // 오버플로우 방지, 홀수 소수들만 체크하면 됨
    {
        if (!primes[i]) // 소수가 아닌 경우
        {
            continue;
        }

        // 에라토스테네스의 체를 이용해 소수의 배수들을 지우기
        for (int j = i * i; j <= MAX; j += i)
        {
            primes[j] = false; // 소수의 배수들은 소수가 아님
        }
    }

    return primes;
}

void getGoldBachPartition(int n, vector<bool> &primes)
{
    int a = 0;
    int b = n;

    // n = a + b를 이루는 두 개의 소수 찾기
    for (int i = 3; i <= n / 2; i += 2)
    {
        if (!primes[i]) // i가 소수가 아닌 경우
        {
            continue;
        }

        int j = n - i;  // i + j = n이 되므로 골드바흐 파티션이 될 수 있다
        if (!primes[j]) // j가 소수가 아니라면
        {
            continue;
        }

        a = i;
        b = j;
        cout << n << " = " << a << " + " << b << "\n";
        return;
    }

    // 못 찾은 경우
    cout << "Goldbach's conjecture is wrong.\n";
}

int main()
{
    // 입출력 속도를 증가시키는 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 연산 & 출력
    vector<bool> primes = getPrimes();
    while (n != 0)
    {
        getGoldBachPartition(n, primes);
        cin >> n;
    }
}