"""This is a horrible solution :D"""
def control_root(n):
    while n > 10:
        n = digital_root(n)
    return n


def digital_root(n):
    if n < 10:
        return n
    else:
        first = first_digit(n)
        print(first)
        return first[0] + digital_root(n - (first[0]*(10**first[1])))

def first_digit(n):
    divides = 0
    while n >= 10: 
        n = n / 10;
        divides += 1

    return [int(n), divides]