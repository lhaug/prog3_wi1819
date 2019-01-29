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
    
    plzs = sorted(dic.items())
    for plz, plz_dict in plzs:
        ausgabe = "{}:".format(plz)
        sorted_plz_dict = sorted(plz_dict.items())
        erg = [" {}({}) ".format(x, y) for x, y in sorted_plz_dict]
        for e in erg:
            ausgabe = ausgabe + e
        print(ausgabe)
    
statistik("text.txt")
        