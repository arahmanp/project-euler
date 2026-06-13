#include <bits/stdc++.h>
using namespace std;

int main() {
    int factorial[10];

    factorial[0] = 1;

    for(int i = 1; i < 10; i++) factorial[i] = factorial[i - 1] * i;

    int sum = 0;

    for(int i = 10; i < 2540160; i++) {
        int n = i;
        int fact_sum = 0;

        while(n != 0) {
            fact_sum += factorial[n % 10];
            n /= 10;
        }

        if(i == fact_sum) sum += i;
    }

    cout << sum;

    return 0;
}