from collections import defaultdict

def sieve_of_eratosthenes(limit):
    is_prime = [True] * limit
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, limit, i):
                is_prime[j] = False
    return is_prime

def solve():
    # 1. Cari semua prima 4 digit
    is_prime = sieve_of_eratosthenes(10000)
    primes_4_digit = [x for x in range(1000, 10000) if is_prime[x]]
    
    # 2. Kelompokkan berdasarkan permutasi digit
    permutation_map = defaultdict(list)
    for prime in primes_4_digit:
        # Urutkan digit sebagai key (misal: 1487 -> "1478")
        sorted_digits = "".join(sorted(str(prime)))
        permutation_map[sorted_digits].append(prime)
    
    # 3. Cari deret aritmatika di setiap kelompok
    for key, prime_list in permutation_map.items():
        if len(prime_list) < 3:
            continue
            
        # Cek kombinasi 3 angka di dalam list
        n = len(prime_list)
        for i in range(n):
            for j in range(i + 1, n):
                p1 = prime_list[i]
                p2 = prime_list[j]
                p3 = p2 + (p2 - p1) # Angka ketiga yang seharusnya
                
                # Pastikan angka ketiga ada di list permutasi yang sama
                if p3 in prime_list and p1 != 1487: 
                    # p1 != 1487 dipakai untuk melewati contoh yang sudah ada di soal
                    return f"{p1}{p2}{p3}"

print("Jawabannya adalah:", solve())
