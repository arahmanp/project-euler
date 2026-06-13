#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if(n <= 1) return false;

  for(int i = 2; i * i <= n; i++) {
    if(n % i == 0) return false;
  }

  return true;
}

int main() {
  int best = -1e9;
  int ans;

  for(int a = -999; a < 1000; a++) {
    for(int b = -1000; b <= 1000; b++) {
      int i = 0;

      while(isPrime(i*i + a*i + b)) {
        i++;
      }

      if(i > best) {
        best = i;
        ans = a * b;
      }
    }
  }

  cout << ans << ' ' << best << '\n';

  return 0;
}
