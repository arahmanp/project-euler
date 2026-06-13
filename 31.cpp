#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n = 200;

  ll dp[n + 1];
  // Inisialisasi seluruh array dp dengan 0
  memset(dp, 0, sizeof(dp)); 
  dp[0] = 1;

  vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

  // Kunci perbaikan: LOOP KOIN DI LUAR
  for(auto c : coins) {
    for(int i = c; i <= n; i++) { // Dimulai dari i = c untuk efisiensi
      dp[i] += dp[i - c];
    }
  }

  cout << dp[n] << "\n";

  return 0;
}