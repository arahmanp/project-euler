#include <ios>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 100'000;

    std::vector<int> primes;
    std::vector<bool> eliminated(n + 1, false);

    for(ll i = 2; i <= n; i++) {
        if(!eliminated[i]) {
            primes.push_back(i);

            for(ll j = i * i; j <= n; j += i) {
                eliminated[j] = true;
            }
        }
    }

    std::cout << primes.size() << '\n';

    std::vector<int> num_primes_by_digit(6, 0);

    for(auto el : primes) {
        if(el >= 10000) num_primes_by_digit[5]++;
        else if(el >= 1000) num_primes_by_digit[4]++;
        else if(el >= 100) num_primes_by_digit[3]++;
        else if(el >= 10) num_primes_by_digit[2]++;
        else if(el >= 1) num_primes_by_digit[1]++;
    }

    for(int i = 1; i <= 5; i++) {
        std::cout << i << ": " << num_primes_by_digit[i] << '\n';
    }

    return 0;
}