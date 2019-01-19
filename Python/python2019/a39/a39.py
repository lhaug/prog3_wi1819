'''
Created on 15.01.2019

@author: Lea
'''
class Messwert():
   
    def __init__(self, *line):
        begin = str(line[0]).replace("'", "")
        if "," in line[0]:
            cut = begin.split(",")
            zeitpunkt = cut[0]
            temperatur = cut[1]
        else:
            zeitpunkt =begin
            temperatur=line[1]
        self._zeitpunkt = str(zeitpunkt)
        self._temperatur = float(temperatur)
        
    def __str__(self):
        return("'{}',{}".format(str(self._zeitpunkt), str(self._temperatur)))
        

if __name__ == "__main__":
    mw = Messwert("'2019-01-11 17:45:01.356640',19.5")
    print(mw)
    mw = Messwert('2019-01-11 17:45:01.356640',19.5)   
    print(mw)     