# -*- coding: utf-8 -*-
"""
Created on Mon Oct 19 19:52:44 2020

@author: 90730
"""
step=0
def hnt(n,x,y,z):
    global step
    if n==1:
        step+=1
        print(step,x,' move to ',z) #x移动到z
    else:
        hnt(n-1,x,z,y)              #x上的n-1个移动到y
        step+=1
        print(step,x,' move to ',z) #x上的移动到z
        hnt(n-1,y,x,z)              #y上的n-1个移动到z

n=int(input('你要玩几个盘子\n'))
hnt(n,'x','y','z')