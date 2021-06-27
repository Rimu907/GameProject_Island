# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 11:39:10 2020

@author: NANDI GUO-14311495
"""
space='-------------------------------------------------------------'
def prt():                              #for clear codes 
    print(f'Is your number greater (>), equal (=), or less (<) than {mid}?')
    print(f'Please answer <,=, or >!\n{space}')
    
min,max = 1,100                         #modify range here
print(f'Think of a number between {min} and {max}!') 
count=0                                 #let's count from 0

while True:                             
        mid=(min+max)//2                #get middle number between min and max
        prt()                                     
        guess=str(input(''))            #Our guess is string type
        count=count+1                   #count+1 after press key      
                        
        if guess=='>':                  #mid became new min number, from new_min to max
                                        #min-1=mid --> min=mid+1
            min=mid+1                   #solved 'max' problem,eg.1-100 however 1-99                                                       
                 
        elif guess=='<':                #mid became new max number, from min to new_max
                                        #max+1=mid --> max=mid-1
            max=mid-1                   #solved 'min' problem,eg.1-100 however 2-100 
              
        elif guess=='=':            
            print(f'\nGG I have guessed it!\nI needed {count} times!')
            break
                                                                
        else:
            print('Error! Please try to enter the right format.')
            count=count-1               #make sure error is not counted in total times,
                                        #count-1+1=count, keep count stay the same value
        if (max+1)==(min-1)+1:
            print('\nIt\'s obvious you lied to me')
            break                       #regard max+1 as max number, min-1 as min number
                                        #thus max=min+1,eg.when 100=99+1, true
                                        #there is no number between 100 and 99.Lied.