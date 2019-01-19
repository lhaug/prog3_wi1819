'''
Created on 14.01.2019

@author: Lea
'''
# coding: utf-8
from sys import argv

dat = argv[-1]

alphabet = "eniastruhdlcmogkwbzfvpjxyq"

all_chars = [char.lower() for line in open(dat) for char in line]

#Buchstaben auszaehlen
counted = {}
for x in all_chars:
    if counted.get(x):
        counted[x]=str(int(counted[x])+1)
    elif x in alphabet:
        counted[x] = str(1)


#counted sortieren und umrechentabelle erstellen
sorted_charcounter_array = sorted(counted.items(), key=lambda x : int(x[1]), reverse=True)
sorted_chars = [x[0] for x in sorted_charcounter_array]
table = dict(zip(sorted_chars,alphabet))

x = "".join(map(lambda x: table.get(x, x), all_chars))

print(x)
        