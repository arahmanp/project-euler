#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string plain;

  cin >> plain;

  stack<char> s;
  string tmp = "";

  vector<string> names;

  for(auto c : plain) {
    if(c == '\"') {
      if(!s.empty() && s.top() == c) {
        names.push_back(tmp);
        tmp = "";
        s.pop();
      } else {
        s.push(c);
      }
    } else {
      if(!s.empty()) {
        tmp += c;
      }
    }
  }

  sort(names.begin(), names.end());

  ll ans = 0;

  for(int i = 0; i < names.size(); i++) {
    int score = 0;

    for(auto c : names[i]) {
      score += ((int)c - 64);
    }

    score *= (i + 1);

    ans += (ll)score;
  }

  cout << ans;

  return 0;
}
