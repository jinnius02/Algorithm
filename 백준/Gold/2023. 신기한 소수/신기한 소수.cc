#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num < 2) return false; // 2보다 작은 수는 소수가 아님
    for (int i = 2; i <= sqrt(num); ++i) { // 2부터 num의 제곱근까지 검사
        if (num % i == 0) return false; // 나누어 떨어지는 수가 있으면 소수가 아님
    }
    return true; // 나누어 떨어지는 수가 없으면 소수
}

// 백트래킹을 통해 N자리 신기한 소수를 찾는 함수
void findAmazingPrimes(int num, int digits, int N) {
    if (digits == N) { // 현재 자리수가 N과 같다면
        cout << num << endl; // 신기한 소수 출력
        return; // 재귀 종료
    }

    for (int i = 1; i <= 9; ++i) { // 1부터 9까지 숫자를 붙여서 새로운 수를 생성
        int nextNum = num * 10 + i; // 현재 수에 i를 붙여서 새로운 수 생성
        if (isPrime(nextNum)) { // 새로운 수가 소수라면
            findAmazingPrimes(nextNum, digits + 1, N); // 재귀 호출로 다음 자리 수 검사
        }
    }
}

int main() {
    int N;
    cin >> N; // 사용자로부터 N 입력 받음

    // 1자리 소수로 시작
    vector<int> firstPrimes = {2, 3, 5, 7}; // 한 자리 소수 초기화
    for (int prime : firstPrimes) { // 각 한 자리 소수에 대해
        findAmazingPrimes(prime, 1, N); // 백트래킹 시작
    }

    return 0;
}