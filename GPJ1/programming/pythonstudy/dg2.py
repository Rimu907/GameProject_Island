def dg(n,x,y,z):
    if n==1:
        print(x,'-->',z)
    else:
        dg(n-1,x,z,y)
        #将前n-1个盘子x到y
        print (x,'-->',z)
        dg(n-1,y,x,z)

n = int(input('input hannuota v: '))
dg(n,'x','y','z')
