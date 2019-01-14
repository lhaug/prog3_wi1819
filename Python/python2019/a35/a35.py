'''
Created on 14.01.2019

@author: Lea
'''
# coding: utf-8
from sys import argv
from itertools import count

dat = argv[-1]

alphabet = "abcdefghijklmnopqrstuvwxyz"

all_chars = [char.lower() for line in open(dat) for char in line]

#Buchstaben auszaehlen
counted = {}
print(counted.get('a'))
for x in all_chars:
    if counted.get(x):
        counted[x]=str(int(counted[x])+1)
    elif x in alphabet:
        counted[x] = str(1)

print(counted)

#counted sortieren und umrechentabelle erstellen
table = dict(zip(sorted(counted, key=counted.get, reverse=True),alphabet))
x = sorted(counted.items(), key=lambda x : int(x[1]))
x = sorted((key) for (key,value) in counted.items())
print(x)
        