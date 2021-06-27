# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 09:43:10 2020

@author: 90730
"""

import random
min=1
max=10
s = random.randint(min,max)
count=0

while True:
    try:
        guess=int(input('what is ur guess\n'))
        if (guess>max) or (guess<min):
            print('value excess limit')
            continue
    except ValueError:
        print('The Value is wrong')
        continue
    count=count+1
    if guess == s:
        print('smart')
        break
    elif guess < s:
        print('Bigger')
    else:
        print('smaller')
        
print(f'YOU used {count} times guess')