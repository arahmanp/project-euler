#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vii generate_prime_factors(int n) {
  vii res;

  for(int i = 2; i * i <= n; i++) {
    int a = 0;

    while(n % i == 0) {
      a++;
      n /= i;
    }

    if(a != 0) res.push_back({i, a});
  }

  if(n > 1) res.push_back({n, 1});

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num = 0;

  for(int i = 210; i <= 500'000; i++) {
    int n = i;

    set<ii> factors;

    vii a = generate_prime_factors(n);

    if(a.size() != 4) continue;

    vii b = generate_prime_factors(n + 1);

    if(b.size() != 4) continue;

    vii c = generate_prime_factors(n + 2);

    if(c.size() != 4) continue;

    vii d = generate_prime_factors(n + 3);

    if(d.size() != 4) continue;

    for(auto el : a) factors.insert(el);
    for(auto el : b) factors.insert(el);
    for(auto el : c) factors.insert(el);
    for(auto el : d) factors.insert(el);

    if(factors.size() != 16) continue;

    num++;

    cout << n << '\n';
  } 

  cout << num << '\n';

  return 0;
}

