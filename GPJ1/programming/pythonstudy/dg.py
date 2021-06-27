def dg(n):
    if n<1:
        print('wrong value')
        return -1
    
    if n == 1 or n == 2:
        return 1
    else:
        return dg(n-1) + dg(n-2)

num = int(input("ur value: "))
result = dg(num)

if result != -1:
    print('total are: %d' % result)
