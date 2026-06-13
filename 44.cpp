#include <cmath>
#include <cstdlib>
#include <iostream>

typedef long long ll;

ll p(int n) {
    return (3 * n * n - n) / 2;
}

bool is_p(ll x) {
    double tmp = (1.0 + sqrt(1.0 + 24 * x)) / 6.0;
    int r = (int)tmp;

    if(p(r) == x) return true;

    return false;
}

int main() {
    ll best = 9e18;

    for(int i = 2; i <= 10000; i++) {
        for(int j = i - 1; j >= 1; j--) {
            ll p_i = p(i);
            ll p_j = p(j);

            ll sum = p_i + p_j;
            ll d = abs(p_i - p_j);

            if(d >= best) break;

            if(is_p(sum) && is_p(d)) {
                best = d;
                break;
            }
        }
    }

    std::cout << best;

    return 0;
}
