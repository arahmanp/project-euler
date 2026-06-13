#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> memo(1000);

ll u(int u1, int b1, int b2, int n) {
  if(n == 1) {
    memo[n] = u1;
    return u1;
  }

  ll ans = u(u1, b1, b2, n - 1) + b2 * (n - 1) + (b1 - b2);

  memo[n] = ans;

  return ans;
}

int main() {
  ll a, b, c, d;

  a = b = c = d = 0;

  cout << u(1, 8, 8, 501) << '\n';
  for(int i = 1; i <= 501; i++) {
    a += memo[i];
  }

  cout << u(3, 10, 8, 500) << '\n';
  for(int i = 1; i <= 500; i++) {
    b += memo[i];
  }

  cout << u(5, 12, 8, 500) << '\n';
  for(int i = 1; i <= 500; i++) {
    c += memo[i];
  }

  cout << u(7, 14, 8, 500) << '\n';
  for(int i = 1; i <= 500; i++) {
    d += memo[i];
  }

  cout << a + b + c + d << '\n';

  return 0;
}
