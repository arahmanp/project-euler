#include <cmath>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int value_of(std::string word) {
    int val = 0;

    for(auto c : word) {
        val += (c - 64);
    }

    return val;
}

bool is_triangle_word(std::string word) {
    int value = value_of(word);

    int root_1 = round(
        (-1 + sqrt((double)1 + 8 * value)) /
        2.0
    );

    int root_2 = round(
        (-1 - sqrt((double)1 + 8 * value)) /
        2.0
    );

    if(root_1 * root_2 == -2 * value) return true;

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string text;

    std::cin >> text;

    std::vector<std::string> words;

    std::string tmp = "";

    for(auto c : text) {
        if(c == '\"') continue;

        if(c == ',') {
            words.push_back(tmp);
            tmp = "";
            continue;
        }

        tmp += c;
    }

    words.push_back(tmp);

    int res = 0;

    for(auto el : words) {
        if(is_triangle_word(el)) res++;
    }

    std::cout << res;

    return 0;
}