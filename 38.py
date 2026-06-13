def is_pandigital(s):
    # Cek apakah string s berisi angka '1' sampai '9' tepat satu kali
    return len(s) == 9 and set(s) == set("123456789")

def solve():
    # Loop mundur dari 9487 (maksimal yang mungkin) ke 9123
    for x in range(9487, 9122, -1):
        # Gabungkan x*1 dan x*2
        concatenated = str(x) + str(x * 2)
        
        if is_pandigital(concatenated):
            return concatenated

print("Hasil Pandigital Terbesar:", solve())