#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 10'000;

  vector<int> prime;
  vector<bool> eliminated(n + 1, false);

  for(int i = 2; i <= n; i++) {
    if(!eliminated[i]) {
      prime.push_back(i);

      for(int j = i * i; j <= n; j += i) {
        eliminated[j] = true;
      }
    }
  }

  for(int i = 168; i < prime.size(); i++) {
    string digit = "";
    int x = prime[i];

    int tmp = x;
    while(tmp != 0) {
      int d = tmp % 10;
      digit += (d + '0');
      tmp /= 10;
    }

    sort(digit.begin(), digit.end());

    for(int j = i + 1; j < prime.size(); j++) {
      string digit_y = "";
      int y = prime[j];

      tmp = y;
      while(tmp != 0) {
        int d = tmp % 10;
        digit_y += (d + '0');
        tmp /= 10;
      }

      sort(digit_y.begin(), digit_y.end());

      if(digit != digit_y) continue;

      int diff = y - x;

      int z = y + diff;

      if(z > 9999) break;

      if(eliminated[z]) continue;

      string digit_z = "";

      tmp = z;
      while(tmp != 0) {
        int d = tmp % 10;
        digit_z += (d + '0');
        tmp /= 10;
      }
      
      sort(digit_z.begin(), digit_z.end());

      if(digit != digit_z) continue;

      cout << x << ' ' << y << ' ' << z << '\n';
    } 
  }

  return 0;
}
