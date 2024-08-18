#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    // 에라토스테네스의 체로 소수 구하기
    long long maxLimit = sqrt(B);
    vector<bool> isPrime(maxLimit + 1, true);
    vector<long long> primes;

    // 소수 판별
    for (long long i = 2; i <= maxLimit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= maxLimit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 거의 소수의 개수 세기
    int count = 0;
    for (long long prime : primes) {
        long long num = prime * prime;
        while (num <= B) {
            if (num >= A) {
                count++;
            }
            if (num > B / prime) break; // 오버플로우 방지
            num *= prime;
        }
    }

    // 결과 출력
    cout << count << endl;

    return 0;
}