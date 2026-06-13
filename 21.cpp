#include <bits/stdc++.h>
using namespace std;

int d(int n) {
  int ans = 0;

  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      int a = i;
      int b = n / i;

      ans += a;

      if(b != a && b < n) ans += b;
    }
  }

  return ans;
}

int main() {
  int ans = 0;

  unordered_set<int> us;

  for(int a = 1; a < 10000; a++) {
    int b = d(a);

    if(d(b) == a && a != b) {
      us.insert(a);
      us.insert(b);
    } 
  }

  for(auto el : us) ans += el;

  cout << ans << '\n';

  return 0;
}
