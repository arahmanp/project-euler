#include <bits/stdc++.h>
using namespace std;

int count(int a, int b) {
  int ans = 0;
  vector<int> res;
  unordered_set<int> rem;

  while(1) {
    while(a < b) {
      a *= 10;
    }
    
    int result = a / b;
    int remain = a - b * result;

    if(rem.count(remain)) break;

    res.push_back(result);
    rem.insert(remain);

    ans++;

    if(remain == 0) break;

    a = remain;
  }

  return (rem.count(0)) ? 0 : ans;
}

int main() {
  int best = -1e9;
  int ans;

  for(int d = 2; d < 1000; d++) {
    if(count(1, d) > best) {
      ans = d;
      best = count(1, d);
    }
  }

  cout << ans << '\n';

  return 0;
}
