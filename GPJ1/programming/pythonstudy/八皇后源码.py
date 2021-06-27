# -*- coding: utf-8 -*-
"""
Created on Fri Nov  6 20:06:16 2020

@author: 90730
"""
count=0
SIZE=8

def queens(n) :
    grid = [[0]*n for i in range(n)]
    solve(grid,0)

    
def solve(grid,row):    
    if row == len(grid):
        global count
        count += 1
        print(f'{count}')
        for m in grid:        
            print(m)   
        input('more?')
        
    n = len(grid)
    for col in range(0,n):
        if not possible(grid,row,col):
            continue
        grid[row][col]='Q'
        solve(grid, row+1)
        grid[row][col]=0

def possible(grid,row,col):    
    n = len(grid)
    for i in range(0,n):
        if grid[i][col]=='Q':
            return False
    for i,j in zip(range(row-1,-1,-1),range(col+1,n)):
        if grid[i][j]=='Q':
            return False
    for i,j in zip(range(row-1,-1,-1),range(col-1,-1,-1)):
        if grid[i][j]=='Q':
            return False
    return True

print(queens(SIZE))