#include <iostream>
#include <string>
int main() {
    std::string frac = "";

    int i = 1;
    while(frac.size() < 1e6) {
        frac += std::to_string(i);
        i++;
    }

    int res = 1;
    
    i = 1;
    while(i <= 1e6) {
        res *= (frac[i - 1] - '0');
        i *= 10;
    }

    std::cout << i << ' ' << res << '\n';

    return 0;
}