'''
Created on 18.12.2018

@author: Lea
'''

#i
l1 = [x*x*x for x in range(1,10) if ((x*x*x)%2 == 0)]
print(l1)

#ii
z = 12
l2 = [x for x in range(2,z) if (z%x == 0)]
print(l2)

#iii
def isPrim(z):
    if [x for x in range(2,z) if (z%x == 0)] == []:
        return True
    else:
        return False

l3 = [x for x in range(10000, 10100) if isPrim(x)]

print(l3)