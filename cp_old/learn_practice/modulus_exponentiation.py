def modExp(a, n):
    if(n > 0):
        if((n & 1) == 1):
            return (a * modExp(a, n-1))
        else:
            return modExp(a**2, n >> 1)
    return 1


print(modExp(5, 5))
