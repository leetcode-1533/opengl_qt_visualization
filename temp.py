# -*- coding: utf-8 -*-
"""
Created on Mon Feb 16 20:09:51 2015

@author: y1275963
"""
from collections import deque

if __name__ == "__main__":
    x_len = 3
    y_len = 3
    z_len = 3
    
    test = deque(maxlen=x_len*y_len+x_len+2)
    i = 0
    
    while len(test) != test.maxlen:
        test.append(i)
        i = i + 1
        
    for z in range(z_len - 1):
        for y in range(y_len - 1):
            for x in range(x_len - 1):
                print test[0]
                test.append(i)
                i = i + 1
            test.append(i)
            i = i + 1
        for y_length in range(y_len):
            test.append(i)
            i = i + 1
        
            
                
                
            
            
            