#include <bits/stdc++.h>
using namespace std;

const int MAXI = 1000000;
bool is_prime[MAXI];

// 1. Sieve of Eratosthenes untuk saring prima O(1) look-up
void sieve() {
    fill(is_prime, is_prime + MAXI, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAXI; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXI; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    sieve();

    // Basis awal: 2, 3, 5, 7 adalah circular prime (4 buah)
    int res = 4; 

    // Loop dari 11 sampai 1 juta (skip angka genap lewat i += 2)
    for (int i = 11; i < MAXI; i += 2) {
        if (!is_prime[i]) continue;

        int temp = i;
        int digits_count = 0;
        int multiplier = 1; // Ini untuk menyimpan nilai 10^(d-1)
        bool valid_digits = true;

        // 2. Ekstrak digit sekaligus cek eliminasi & hitung multiplier
        while (temp > 0) {
            int d = temp % 10;
            // Jika mengandung angka genap atau 5, otomatis gagal saat dirotasi
            if (d == 0 || d == 2 || d == 4 || d == 5 || d == 6 || d == 8) {
                valid_digits = false;
                break;
            }
            digits_count++;
            if (digits_count > 1) {
                multiplier *= 10;
            }
            temp /= 10;
        }

        if (!valid_digits) continue;

        // 3. Lakukan rotasi secara matematis
        int num = i;
        bool is_circular = true;

        for (int r = 0; r < digits_count - 1; r++) {
            int first_digit = num / multiplier;
            int remainder = num % multiplier;
            num = remainder * 10 + first_digit; // Rumus rotasi matematis

            if (!is_prime[num]) {
                is_circular = false;
                break;
            }
        }

        if (is_circular) {
            res++;
        }
    }

    cout << res << endl;
    return 0;
}