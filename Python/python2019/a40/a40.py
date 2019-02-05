'''
Created on 19.01.2019

@author: Lea
'''
from a39.a39 import Messwert
class Messreihe():
    
    def __init__(self, strings=None):
        self._messreihe = set()
        if strings != None:           
            for i in strings:
                if type(i) != Messwert:
                    i = Messwert(i)
                self._messreihe.add(i)
    
    def __len__(self):
        return len(self._messreihe)
    
    def add(self, *mw):
        for m in mw:
            self._messreihe.add(m)
            
    def __add__(self, other):
        new_one = self._messreihe | other._messreihe # oder weil es zwei mengen sind
        return new_one
    
    def __iter__(self):
        self.pos = -1
        return self
        
    def __next__(self):
        self.pos += 1
        if self.pos >= len(self._messreihe):
            raise StopIteration
        return self[self.pos]
    
    def __getitem__(self, index):
        mwlist = list(self._messreihe)
        return mwlist[index]
        
    
mr = Messreihe(open('messwerte.csv'))  
print(len(mr))
mw1 =("'2019-01-15 17:45:01.356640',19.5")
#mr.add(mw1)
#print(len(mr))
mw2 = ("'2019-01-15 17:45:01.356640',19.5")
mw3 = ("'2019-01-15 17:45:01.356640',19.3")
#mr.add(mw2, mw3)
#print(len(mr))
mr2 = Messreihe([mw1, mw2, mw3])
print(len(mr2))
mr3 = mr+mr2
print(len(mr3))
counter = 0
for m in mr:
    counter += 1
print(counter)

    