'''
Created on 08.02.2019

@author: Lea
'''
import re
def isHawaiianREG(w):
    vokale = "[AEIOU]"
    konsonanten = "[HKLMNPW']"
    reg = "^(("+konsonanten+"("+vokale+")+)|"+vokale+")*"+vokale+"$"
    hawai_pattern = re.compile(r''+reg+'', re.IGNORECASE)
    match = hawai_pattern.match(w)
    if match != None:
        if match.group() == w:
            return True
        else:
            return False
    else:
        print("None")
        return False

def isHawaiian(w):
    vokale = "AEIOUaeiou"
    konstanten = "HKLMNPW'hklmnpw"
    if w[-1] not in vokale:
        return False
    index = -1
    for x in w:
        index += 1
        if x not in vokale and x not in konstanten:
            return False
        if x in konstanten:
            next = (index+1)
            if next < len(w):
                if w[next] == "'":
                    return False
                if w[next] in konstanten:
                    return False
    return True

def extractHi(iterable):
    for items in iterable:
        items = items.replace(".", "")
        items = items.replace(",", "")
        items = items.replace("!", "")
        items = items.replace("?", "")
        items = items.replace(":", "")
        items = items.replace(";", "")
        item = items.split()
        if type(item) == list:
            for i in item:
                if isHawaiian(i):
                    yield i
        else:
            if isHawaiian(item):
                yield item
                
                
