# -*- coding: utf-8 -*-
"""
Created on Sun Oct 11 21:18:05 2020

@author: 90730
"""
name=str(input('What\'s ur name\n'))

while True:
    try:
        time=int(input('What\'s the time\n'))
        break
    except ValueError:
        print('sry,that\'s the wrong format')
        
print(f'I can tell the time is {time}')

if (600<time<1200):
    print(f'Good morning\n{name}, Time to get up!')
elif (1200<=time<=1800):
    print(f'Good afternoon\n{name}, Time to eat something!')
elif (1800<time<2400):
    print(f'Good night\n{name}, Time to sleep with Nezuko!')
else:
    print('I guess its too late right now, '+ name)