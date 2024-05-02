

def test(b, c, d):
    """Calculates the value of 'a' by adding 'b' and 'c', then repeatedly multiplying 'a' by the sum of 'a' and 'd', incrementing 'd' by a factor of 2 each time, until the sum of 'a' and 'd' reaches or exceeds 10000."""
    a = b + c
    z = a + d
    p = 0
    while (a + z < 10000):
        a = z * a
        z *= 2
    return a

m = test(1, 2, 3)
print(m)

