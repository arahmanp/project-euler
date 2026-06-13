#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d(int n) {
  int ans = 0;

  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      int a = i;
      int b = n / i;
      
      ans += a;

      if(a != b && b < n) ans += b;
    }
  }

  return ans;
}

bool isExist(const vector<int>& v, int x) {
  int l, r, ans = -1;
  l = 0;
  r = v.size() - 1;

  while(l <= r) {
    int mid = l + (r - l) / 2;

    if(x < v[mid]) {
      r = mid - 1;
    } else if(x > v[mid]) {
      l = mid + 1;
    } else {
      ans = mid;
      break;
    }
  }

  return (ans != -1);
}

int main() {
  int limit = 28123;

  vector<int> abundants;

  for(int i = 1; i < limit; i++) {
    if(d(i) > i) abundants.push_back(i);
  }

  ll ans = 0;

  for(int i = 1; i < limit; i++) {
    bool possible = false;

    for(auto a : abundants) {
      int b = i - a;

      if(isExist(abundants, b)) {
        possible = true;
        break;
      } 
    }

    if(!possible) ans += (ll)i;
  }

  cout << ans << '\n';

  return 0;
}
