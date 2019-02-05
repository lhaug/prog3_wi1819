'''
Created on 15.01.2019

@author: Lea
'''

class Messwert():
   
    def __init__(self, *line):
        begin = str(line[0]).replace("'", "")
        if "," in line[0]:
            # in einem String
            cut = begin.split(",")
            zeitpunkt = cut[0]
            temperatur = cut[1].split("\n")[0]
        else:
            # in zwei parametern
            zeitpunkt =begin
            temperatur=line[1]
        self._zeitpunkt = str(zeitpunkt)
        self._temperatur = float(temperatur)
        
    def __str__(self):
        return("'{}',{}".format(str(self._zeitpunkt), str(self._temperatur)))
    
    def __repr__(self):
        return("Messwert('{}',{})".format(str(self._zeitpunkt), str(self._temperatur)))
    
    #Problem: other ist ein Tupel, cast in Messwert geht auch nicht
    def __eq__(self, other):
        x = self._zeitpunkt
        y = other._zeitpunkt
        if x == y:
            if self._temperatur == other._temperatur:
                return True
        else:
            return False
        
    def __lt__(self, other):
        if self._zeitpunkt < other._zeitpunkt:
            return True
        elif self._zeitpunkt == self._zeitpunkt and self._temperatur < other._temperatur:
            return True
        else:
            return False
        
    def __hash__(self):
        return hash((self._zeitpunkt, self._temperatur))       
    
if __name__ == "__main__":
    mw1 = Messwert("'2019-01-15 17:45:01.356640',19.5")
    print(mw1)
    mw2 = Messwert('2019-01-11 16:45:01.356640',19.5)   
    print(mw2) 
    mw3 = Messwert("'2019-01-15 17:45:01.356640',20.5")
    print(mw3)
    mwlist = [mw1, mw2, mw3]
    print(eval(repr(mw1))== mw1)
    print(mw1 < mw2)
    print(mw2 < mw1)
    print(mw1 < mw3)
    print(mw3 < mw1)
    print(sorted(mwlist))
    print( set((mw1, mw2)) )
    
    