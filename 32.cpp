#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    unordered_set<int> us;
    ll ans = 0;

    for(int i = 1; i <= 10000; i++) {
        for(int j = 1; j <= 10000; j++) {
            vector<bool> used(10, false);
            bool possible = true;
            int tmp, nDigits = 0;

            int product = i * j;

            tmp = i;
            while(tmp != 0 && possible) {
                int digit = tmp % 10;
                if(used[digit] == true || digit == 0) {
                    possible = false;
                    break;
                }
                used[digit] = true;
                nDigits++;
                tmp /= 10;
            }

            tmp = j;
            while(tmp != 0 && possible) {
                int digit = tmp % 10;
                if(used[digit] == true || digit == 0) {
                    possible = false;
                    break;
                }
                used[digit] = true;
                nDigits++;
                tmp /= 10;
            }

            tmp = product;
            while(tmp != 0 && possible) {
                int digit = tmp % 10;
                if(used[digit] == true || digit == 0) {
                    possible = false;
                    break;
                }
                used[digit] = true;
                nDigits++;
                tmp /= 10;
            }

            if(nDigits != 9) possible = false;

            if(possible) {
                cout << i << " * " << j << " = " << product << endl;
                us.insert(product);
            }
        }
    }

    for(auto el : us) ans += (ll)el;

    cout << ans;

    return 0;
}