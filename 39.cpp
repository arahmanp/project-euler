#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> n(1001, std::pair<int, int>(0, 0));

    for(int a = 1; a <= 1000; a++) {
        for(int b = a; b <= 1000; b++) {
            int c = std::round(sqrt((double)a*a + b*b));

            int p = a + b + c;
            
            if(a*a + b*b == c*c) {
                if(p <= 1000) {
                    n[p].first++;
                    n[p].second = p;
                }
            }
        }
    }

    int best = -1e9;
    int res;
    
    for(auto [num, p] : n) {
        if(best < num) {
            best = num;
            res = p;
        }
    }

    std::cout << res << '\n';

    return 0;
}