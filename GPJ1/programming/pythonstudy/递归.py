def fac(n):
    if n==1:
        return 1
    else:
        return n * fac(n-1)

number = int(input("input "))
result = fac(number)
print("%d 阶乘是: %d" % (number,result))

