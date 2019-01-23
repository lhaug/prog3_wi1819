'''
Created on 22.01.2019

@author: Lea
'''
def statistik(dateiname):
    lines = open(dateiname)
    dic = {}
    for line in lines:
        linesplit = line.split(";")
        plz = linesplit[0]
        name = linesplit[1]
        wert = linesplit[2].split()[0]
        if plz in dic:
            if name in dic[plz]:
                dic[plz][name] = int(dic[plz][name])+int(wert)
            else:
                dic[plz][name] = wert
        else:
            dic[plz] = {name: wert}
        
    print(dic)
    
    keys = sorted(dic)
    for key in keys:
        names = sorted(dic[key])
        x = ["{}: {}({}) ".format(key, x, y) for x, y in names]
        print(x)
    
statistik("text.txt")
        