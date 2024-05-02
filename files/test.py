

def test(b, c, d):
    a=b+c
    z=a+d
    p=0
    while (a+z<10000):
        a=z*a
        z*=2
    return a


m = test(1, 2, 3)

print(m)