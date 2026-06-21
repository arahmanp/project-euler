#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 1'000'000;

  vector<long long> primes;
  vector<bool> eliminated(n + 1, false);

  for(long long i = 2; i <= n; i++) {
    if(!eliminated[i]) {
      primes.push_back(i);

      for(long long j = i * i; j <= n; j += i) {
        eliminated[j] = true;
      }
    }
  }

  int n_prime = primes.size();

  vector<long long> sum(n_prime + 1, 0);

  for(int i = 1; i < n_prime; i++) sum[i] = sum[i - 1] + primes[i];

  for(int width = 550; width >= 0; width--) {
    for(int i = 0; i <= n_prime - width; i++) {
      long long x = sum[i + width - 1];

      if(i > 0) x -= sum[i - 1];

      if(x < n) {
        if(!eliminated[x]) {
          cout << x << '\n';
          return 0;
        }
      }
    }
  }

  return 0;
}

