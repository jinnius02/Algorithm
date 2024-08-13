#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n); // 동전의 가치를 저장할 벡터
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // 각 동전의 가치 입력 받기
    }

    vector<int> dp(k + 1, 0); // dp[x]는 금액 x를 만들 수 있는 경우의 수
    dp[0] = 1; // 0원을 만드는 경우는 아무 동전도 사용하지 않는 1가지 경우

    // 각 동전에 대해서
    for (int coin : coins) {
        // coin 가치부터 k원까지 각 금액을 만들 수 있는 경우의 수를 업데이트
        for (int amount = coin; amount <= k; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    cout << dp[k] << endl; // k원을 만들 수 있는 경우의 수 출력
    return 0;
}
