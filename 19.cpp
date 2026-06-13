#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;

  int day = 1;

  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for(int y = 1901; y <= 2000; y++) {
    bool leap = (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0);

    for(int m = 1; m <= 12; m++) {
      int num_days = days[m];

      if(leap && m == 2) num_days++;

      for(int d = 1; d <= num_days; d++) {
        day++;
        day %= 7;

        if(day == 0 && d == 1) ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
