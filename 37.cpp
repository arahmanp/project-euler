#include <bits/stdc++.h>
using namespace std;

const int MAXI = 999999;

int main() {
    vector<bool> is_prime(MAXI + 1, true);

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= MAXI; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= MAXI; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int res = 0;
    int num = 0;

    for(int i = 11; i <= MAXI; i++) {
        if(!is_prime[i]) continue;

        bool possible = true;

        int tmp = i;
        while(tmp != 0) {
            if(!is_prime[tmp]) {
                possible = false;
                break;
            }

            tmp -= (tmp % 10);
            tmp /= 10;
        }

        if(!possible) continue;

        tmp = i;
        int x = 10000;
        while(tmp > 0) {
            if(!is_prime[tmp]) {
                possible = false;
                break;
            }

            tmp = i % x;
            x /= 10;
        }

        if(!possible) continue;

        num++;
        res += i;
    }

    cout << num << '\n' << res;
}