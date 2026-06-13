#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int idx = 0;

  do {
    idx++;
    
    if(idx == 1'000'000) {
      for(auto el : digits) cout << el;
      break;
    }
  } while(next_permutation(digits.begin(), digits.end()));

  return 0;
}
