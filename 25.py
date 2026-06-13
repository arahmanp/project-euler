f1 = 1
f2 = 1
fn = f1 + f2

i = 3

while(len(str(fn)) != 1000):
    f1 = f2
    f2 = fn
    fn = f1 + f2
    i += 1


print(i)
