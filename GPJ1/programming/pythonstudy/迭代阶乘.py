# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 16:10:25 2020

@author: 90730
"""

def fac(n):
        for i in range(1,n):
            
                n = i*n
                print(f'从{i}开始,{n}')
        print (n)
    
m = int(input("请输入一个正整数:"))
result = fac(m)
