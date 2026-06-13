#include <algorithm>
#include <iostream>
const int BOUND = 9'876'543;

bool is_pandigital(int n) {
    int mask = 0;
    int max_digit = -1;
    
    while(n != 0) {
        int digit = n % 10;

        if(mask & (1<<digit)) return false;

        max_digit = std::max(max_digit, digit);
        mask |= (1<<digit);
        n /= 10;
    }
    
    return mask == (1<<(max_digit + 1)) - 2;
}

bool is_prime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }

    return true;
}

int main() {
    for(int i = 9'876'543; i >= 1; i--) {
        if(is_pandigital(i) && is_prime(i)) {
            std::cout << i << '\n';
            return 0;
        }
    }
}