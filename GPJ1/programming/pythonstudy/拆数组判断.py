while True:
        def pyt(n):
                l=[]
                n=str(n)
                for x in n:
                        l.append(int(x))
                #将数字拆为数组
                a,b,c,d = int(l[0]),int(l[1]),int(l[2]),int(l[3])
                #重新将每个数转为整形
                if a==b==3 or b==c==3 or c==d==3: #判断不能两个连续=3
                        return (print('false'))
                else:
                        if d % 4 == 0: #最后一个数能被4整除
                                return(print('true'))
                        else:
                                return(print('false'))

        print('Enter the value:')
        m = int(input())
        if m < 1000 or m > 9999:
                print('wrong value')
        else:
                pyt(m)