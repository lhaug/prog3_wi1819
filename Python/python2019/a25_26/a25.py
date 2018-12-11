'''
Created on 04.12.2018

@author: Lea
'''

def devocalize(s):
    vokale = "aeiou"
    for e in vokale:
        s = s.replace(e,"")
    
    return(s)
    
print(devocalize("Das ist ein Baerenspass"))

help(devocalize)
