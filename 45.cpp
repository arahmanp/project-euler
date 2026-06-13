#include <cmath>
#include <iostream>

typedef long long ll;

int main() {
    ll res, a;
    bool found = false;

    for(ll j = 144; !found; j++) {
        ll x = 1 - 12 * (2 * j - 4 * j * j);

        if(x % 2 == 0) continue;

        ll y = round(sqrt(x));

        if(y * y != x) continue;

        if((1 + y) % 6 == 0) {
            found = true;
            res = (1 + y) / 6;
            a = j;
        }
    }

    std::cout << a << ' ' << res << ' ' << a * (2 * a - 1);

    return 0;
}