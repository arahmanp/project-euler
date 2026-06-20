#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int main() {
  int num = 10'000;
  int res;

  vi prime_list;
  vb eliminated(num + 1, false);

  for(int i = 2; i <= num; i++) {
    if(!eliminated[i]) {
      prime_list.push_back(i);

      for(int j = i * i; j <= num; j += i) {
        eliminated[j] = true;
      }
    }
  }

  for(int i = 1; i <= num; i += 2) {
    if(eliminated[i]) {
      for(int j = 0; prime_list[j] < i; j++) {
        if(prime_list[j] % 2 == 0) continue;

        int k = (i -  prime_list[j]) / 2;

        int tmp = round(sqrt((double)k));

        if(tmp * tmp == k) break;

        if(prime_list[j + 1] >= i) {
          cout << i << '\n';
          return 0;
        }
      }
    }
  }

  return 0;
}

