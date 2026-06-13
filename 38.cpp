#include <algorithm>
#include <iostream>
#include <string>
int main() {
    int best = 0;

    for(int i = 9123; i <= 9487; i++) {
        bool possible = true;
        
        std::string res = std::to_string(i) + std::to_string(i * 2);

        bool used[10];
        std::fill_n(used, 10, false);

        for(auto c : res) {
            int digit = c - '0';

            if(digit == 0 || used[digit]) {
                possible = false;
                break;
            }

            used[digit] = true;
        }

        if(!possible) continue;

        int res_int = std::stoi(res);

        best = std::max(best, res_int);
    }

    std::cout << best << '\n';

    return 0;
}