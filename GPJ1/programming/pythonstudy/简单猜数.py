print("wait-----------------------------------")

i=10
temp = input ("guess:")
guess = int(temp)
while (guess !=8) and (i>0) :
     
     temp = input ("reguess\n")
     guess = int(temp)
     i=i-1
     if guess == 8:
               print("6666666")
               print("u r so good")
     else:
          if guess < 8:
               print("it should be larger")
          else:
              print("it should be smaller")

print("end!")

