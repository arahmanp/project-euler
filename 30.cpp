#include <bits/stdc++.h>
using namespace std;

int sumPowerDigit(int n) {
  int ans = 0;

  while(n > 0) {
    ans += (int)pow(n % 10, 5);
    n /= 10;
  }

  return ans;
}

int main() {
  int ans = 0;
  
  for(int i = 2; i <= 1000000; i++) {
    if(sumPowerDigit(i) == i) ans += i;
  }

  cout << ans << '\n';

  return 0;
}
