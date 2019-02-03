'''
Created on 19.01.2019

@author: Lea
'''
from a39.a39 import Messwert
class Messreihe():
    
    def __init__(self, strings=None):
        self._messreihe = []
        if strings != None:
            for i in strings:
                if type(i) != Messwert:
                    i = Messwert(i)
                if i not in self._messreihe: #warum läuft es damit so lange?
                    self._messreihe.__iadd__([i])
    
    def __print__(self):
        return self._messreihe
    
    def __len__(self):
        return len(self._messreihe)
    
    def add(self, *mw):
        for m in mw:
            self._messreihe.__iadd__([m])
            
    def __add__(self, other):
        new_one = self
        for e in other._messreihe:
            new_one._messreihe.__iadd__([e])
        return new_one
        
    
mr = Messreihe(open('messwerte.csv'))  
print(len(mr))
mw1 = Messwert("'2019-01-15 17:45:01.356640',19.5")
#mr.add(mw1)
#print(len(mr))
mw2 = Messwert("'2019-01-15 17:45:01.356640',19.5")
mw3 = Messwert("'2019-01-15 17:45:01.356640',19.3")
#mr.add(mw2, mw3)
#print(len(mr))
mr2 = Messreihe([mw1, mw2, mw3])
print(len(mr2))
#mr3 = mr+mr2
#print(len(mr3))

    