# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 11:39:10 2020

@author: NANDI GUO
"""

def prt():
    print(f'Is your number greater (>), equal (=), or less (<) than [{n}]?')
    print('Please answer <,=, or > !\n-----------------------------------')
def prt2():
    print(f'Now I have {m} times left\n-----------------------------------')
def exit():
    if count == 7 and guess!='=':        #7 depends on how many times u enter
        print('\nNooooooo, I lost :c')
        sys.exit()                       #Quit if cant get answer in 7 steps

    
print('Think of a number between 1 and 100!\n----------------------------------')
import random,sys
min,max,n= 1,100,50                      #range 1-100, start with 50% chance
prt()
count=0                                  #let's count from 0

while count<7:  
                                         #Total 7 times
    try:
        guess=str(input())               #Our guess is string type
        count=count+1                    #count for loop
        
        if guess=='>':
            min = n+1                    #n+1 solved the number repeat problem
            n = random.randint(min,max)
            exit()
            prt()
            m=7-count                    #Calculate how many times left
            prt2()     
            continue
        
        elif guess=='<':
            max = n-1                    #n-1 solved the number repeat problem
            n = random.randint(min,max)
            exit()
            prt()
            m=7-count
            prt2()  
            continue
        
        elif guess=='=':            
            print(f'\nGG I have guessed it!\nI used {count} times to get the right answer!')
            break
        
        else:
            m=7-count
            print('Error! Please try to enter the right format.')
            prt2()
      
    except ValueError:
        print('\nIt\'s obvious you lied to me')
        break                           #lie, if not in range,if you lied