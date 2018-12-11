'''
Created on 04.12.2018

@author: Lea
'''
print("for-Schleife")

lst = [1, 2, 3]
for e in lst:
    print(e)
    
    
print("als while-Schleife")
    
i=0
while i < len(lst):
    print(lst[i])
    i +=1 
    
    
print("---------")
print("while-Schleife")

m = [5, 3, 6, 8, 1]
i = 0
while i < len(m):
    z=m[i]
    print(z," hoch zwei ist ",z**2)
    i = i+1


print("als for-Schleife")

for e in m:
    print(e," hoch zwei ist ",e**2)
    

