import random
s = random.randint(1,10)

print("wait-----------------------------------")

i=10

temp = input ("guess:")
guess = int(temp)

while (guess !=s) and (i>0) :
     

     i=i-1
     if guess == s:
               print("6666666")
               print("u r so good")
     else:
          if guess < s:
               print("it should be larger")
          else:
              print("it should be smaller")
     temp = input ("reguess\n")
     guess = int(temp)
print("end!")

