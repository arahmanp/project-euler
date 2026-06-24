#include <algorithm>
#include <iostream>
#include <string>
int main() {
    int bound = 1'000'000;

    for(int i = 1; i <= bound; i++) {
        std::string s1 = std::to_string(i);
        std::string s2 = std::to_string(i * 2);
        std::string s3 = std::to_string(i * 3);
        std::string s4 = std::to_string(i * 4);
        std::string s5 = std::to_string(i * 5);
        std::string s6 = std::to_string(i * 6);

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        std::sort(s3.begin(), s3.end());
        std::sort(s4.begin(), s4.end());
        std::sort(s5.begin(), s5.end());
        std::sort(s6.begin(), s6.end());

        if(s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6) {
            std::cout << i;
            return 0;
        }
    }
}