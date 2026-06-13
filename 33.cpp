#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi list_digits(int n) {
    vi res;

    while(n != 0) {
        res.push_back(n % 10);
        n /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    int hasil_pembilang = 1;
    int hasil_penyebut = 1;

    for(int i = 12; i < 99; i++) {
        for(int j = i + 1; j < 99; j++) {
            if(i % 10 == 0 || j % 10 == 0) continue;
            if(i % 11 == 0 || j % 11 == 0) continue;

            int pembilang = i;
            int penyebut = j;

            vi digit_pembilang = list_digits(pembilang);
            vi digit_penyebut = list_digits(penyebut);

            int jumlah_sama = 0;

            int idx_sama_pembilang, idx_sama_penyebut;

            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    if(digit_pembilang[k] == digit_penyebut[l]) {
                        jumlah_sama++;
                        idx_sama_pembilang = k;
                        idx_sama_penyebut = l;
                    }
                }
            }

            if(jumlah_sama != 1) continue;

            int pembilang_akhir = digit_pembilang[1 - idx_sama_pembilang];
            int penyebut_akhir = digit_penyebut[1 - idx_sama_penyebut];

            if(pembilang * penyebut_akhir == penyebut * pembilang_akhir) {
                hasil_pembilang *= pembilang;
                hasil_penyebut *= penyebut;
            }
        }
    }

    int fpb = gcd(hasil_pembilang, hasil_penyebut);
    
    if(fpb != 1) {
        hasil_pembilang /= fpb;
        hasil_penyebut /= fpb;
    }

    cout << hasil_pembilang << ' ' << hasil_penyebut;

    return 0;
}
