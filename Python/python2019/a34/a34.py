'''
Created on 14.01.2019

@author: Lea
'''
from sys import argv

i = "abcdefghijklmnopqrstuvwxyz"
o = "efghijklmnopqrstuvwxyzabcd"

#dat = "a34/verschluesselt.txt"
dat = argv[-1]

all_chars = [char.lower() for line in open(dat) for char in line]
table = dict(zip(o, i))

x = "".join(map(lambda x: table.get(x, x), all_chars))

print(x)
