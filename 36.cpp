#include <bits/stdc++.h>
using namespace std;

// Cek palindrom basis 10 (Matematis murni)
bool is_palindrome_base10(int n) {
    int original = n;
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return original == reversed;
}

// Cek palindrom basis 2 (Bitwise / Matematis murni)
bool is_palindrome_base2(int n) {
    int original = n;
    int reversed = 0;
    while (n > 0) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return original == reversed;
}

int main() {
    // 1. Catat waktu tepat sebelum loop dimulai
    auto start = chrono::high_resolution_clock::now();

    int res = 0;

    // Proses loop utama
    for(int i = 1; i < 1000000; i += 2) {
        if(is_palindrome_base10(i) && is_palindrome_base2(i)) {
            res += i;
        }
    }

    // 2. Catat waktu tepat setelah loop selesai
    auto stop = chrono::high_resolution_clock::now();

    // 3. Hitung selisih waktunya (konversi ke mikrodetik dulu biar presisi)
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // Tampilkan hasil pencarian
    cout << "Hasil: " << res << endl;
    
    // Tampilkan durasi eksekusi dalam milidetik (ms)
    cout << "Waktu Eksekusi Murni: " << duration.count() / 1000.0 << " ms" << endl;

    return 0;
}