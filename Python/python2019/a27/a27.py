'''
Created on 04.12.2018

@author: Lea
'''
def dreh(lst):
    if lst == []:
        return lst;
    else:
        anhang = lst[0]
        lst = dreh(lst[1:])
        lst = lst+[anhang]
        return lst
    
print(dreh([1, 2, 3, 4,5]))