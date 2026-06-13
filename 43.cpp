#include <algorithm>
#include <iostream>
#include <vector>

bool is_valid(std::vector<int> digits) {
    if((digits[1] * 100 + digits[2] * 10 + digits[3]) % 2 != 0) return false;
    if((digits[2] * 100 + digits[3] * 10 + digits[4]) % 3 != 0) return false;
    if((digits[3] * 100 + digits[4] * 10 + digits[5]) % 5 != 0) return false;
    if((digits[4] * 100 + digits[5] * 10 + digits[6]) % 7 != 0) return false;
    if((digits[5] * 100 + digits[6] * 10 + digits[7]) % 11 != 0) return false;
    if((digits[6] * 100 + digits[7] * 10 + digits[8]) % 13 != 0) return false;
    if((digits[7] * 100 + digits[8] * 10 + digits[9]) % 17 != 0) return false;

    return true;

}

int main() {
    std::vector<int> digits = {0, 1, 2, 3, 4, 5,6, 7, 8, 9};
    long long res = 0;

    do {
        if(digits[5] != 0 && digits[5] != 5) continue;

        if(is_valid(digits)) {
            long long n = 0;

            for(long long i = 9, j = 1; i >= 0; i--, j *= 10) {
                n += (long long)digits[i] * j;
            }

            std::cout << n << '\n';

            res += n;
        }
    }while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << res;

    return 0;
}