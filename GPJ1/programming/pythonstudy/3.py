print ("enter\n--------------------------------------")

i=100

while i>0:
    
    grade = input()
    temp = int(grade)
    i-=1
    
    while 2>1:

        if 100 >= temp >= 90:
            print("A")
            break
        elif 90 > temp >= 80:
            print("B")
            break 
        elif 80 > temp >= 60:
            print("C")
            break
        elif 0 <= temp < 60:
            print("D")
            break
        else:
            print("wrong input\n"*5)
            break
            
print ("Exit")
    
