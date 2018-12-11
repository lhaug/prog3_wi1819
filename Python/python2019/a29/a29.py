'''
Created on 04.12.2018

@author: Lea
'''
def h(a, b, c=1000,*d, **e):
    print(a, b, c, d, e)


a = h(17, 21)

b = h(10, 20, 30)

d = h(1, 2, 3, 4, 5, 6, x=7, y=22) 

c = h(1, 2, 3, 4, 5, 6, c=7) #multiple values for argument c
