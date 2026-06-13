#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> n = {
    0,
    3, // 1
    3, // 2
    5, // 3
    4, // 4
    4, // 5
    3, // 6
    5, // 7
    5, // 8
    4, // 9
    3, // 10
    6, // 11
    6, // 12
    8, // 13
    8, // 14
    7, // 15
    7, // 16
    9, // 17
    8, // 18
    8 // 19
  };

  for(int i = 20; i < 1000; i++) {
    if(i >= 100) {
      if(i % 100 == 0) n.push_back(n[i / 100] + 7);
      else {
        int a = (i % 100);
        int b = i - a;

        n.push_back(n[a] + 3 + n[b]);
      } 
    } else if(i % 10 == 0) {
      if(i == 20) n.push_back(6);
      else if(i == 30) n.push_back(6);
      else if(i == 40) n.push_back(5);
      else if(i == 50) n.push_back(5);
      else if(i == 60) n.push_back(5);
      else if(i == 70) n.push_back(7);
      else if(i == 80) n.push_back(6);
      else if(i == 90) n.push_back(6);
    } else {
      int a = (i % 10);
      int b = i - a;

      n.push_back(n[a] + n[b]);
    }
  }

  n.push_back(11);

  int ans = 0;

  for(auto el : n) ans += el;

  cout << ans << '\n';

  return 0;
}
