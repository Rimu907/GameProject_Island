# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 11:39:10 2020

@author: NANDI GUO
"""
space='-------------------------------------------------------------'
def prt():
    print(f'Is your number greater (>), equal (=), or less (<) than {mid}?')
    print('Please answer <,=, or >!\n'+ space)
  
min,max = 1,10
print(f'Think of a number between {min} and {max}!') 
count=0                                 #let's count from 0

while True:
        mid=(max+min)//2
        prt()                                     
        guess=str(input(''))            #Our guess is string type
        count=count+1                          
                        
        if guess=='>':
            min=mid                                                                             
                 
        elif guess=='<':
            max=mid
              
        elif guess=='=':            
            print(f'\nGG I have guessed it!\nI needed {count} times!')
            break
                                                                
        else:
            print('Error! Please try to enter the right format.')
            count=count-1               #make sure error is not counted in total times,
                                        #count-1+1=count, keep count stay the same value
        if max==min+1:
            print('lie')
            break