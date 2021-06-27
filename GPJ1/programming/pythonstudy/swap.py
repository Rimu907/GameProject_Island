def swp(l):
    helper=l[-1]
    l[-1]=l[0]
    l[0]=helper
    print(l)

lst=[1,2,3]
swp(lst)
    
