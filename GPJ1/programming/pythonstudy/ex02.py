# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 11:39:10 2020

@author: NANDI GUO
"""
space='-------------------------------------------------------------'
def prt():
    print(f'Is your number greater (>), equal (=), or less (<) than {n}?')
    print('Please answer <,=, or >!\n'+ space)
    
min,max = 1,100                          #modify range here
print(f'Think of a number between {min} and {max}!')

import random
n = int((min+max)//2)                    #range, start with 50% chance
prt()
count=0                                  #let's count from 0

while True:                                   
    try:
        guess=str(input())               #Our guess is string type
        count=count+1                    #count for loop
        
        if guess=='>':
            min = n+1                    #n+1 solved the random number repeat problem
            n = random.randint(min,max)  #random a number from 'new min' to max
            prt()                      
            continue
        
        elif guess=='<':
            max = n-1                    #n-1 solved the random number repeat problem
            n = random.randint(min,max)  #random a number from min to 'new max'
            prt() 
            continue
        
        elif guess=='=':            
            print(f'\nGG I have guessed it!\nI needed {count} times!')
            break                        #if equal, end program
        
        else:
            print('Error! Please try to enter the right format.')
            count=count-1                #make sure error is not counted in total times,
                                         #count-1+1=count, keep count stay the same value
    except ValueError:                   #e.g 4<n<6, ask 5? enter < or >, ValueError, lie
        print('\nIt\'s obvious you lied to me')
        break                            #lie, if not in range,if you lied, end program