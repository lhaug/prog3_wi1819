'''
Created on 04.12.2018

@author: Lea
'''

print("unsch�n")
def ggt(x, y):
    if x == y:
        return x
    elif x > y:
        return ggt(x-y, y)
    else:
        return ggt(y, x)
        
a = ggt(10,30)
b = ggt(20,30)
c = ggt(2, 5)
d = ggt(8, 6)
e = ggt(7,3)

print(a, b, c, d, e)


print("sch�n aka modulo")

def opt_ggt(x, y):
    if x%y == 0:
        return y
    elif x > y:
        return opt_ggt(x%y, y)
    else:
        return opt_ggt(y, x)
        
a = opt_ggt(10,30)
b = opt_ggt(20,30)
c = opt_ggt(2, 5)
d = opt_ggt(8, 6)
e = opt_ggt(7,3)

print(a, b, c, d, e)

print("---------------aus Datei---------------------")

def mittelwert():
    f = open("a30-ggts.dat", "r")
    summe = 0
    anzahl = 0
    while True:
        s = f.readline()
        if s == "":
            break
        else: 
            value = int(s)
            summe = summe + value
            anzahl = anzahl + 1
    print("Summe: ",summe)
    print("Anzahl: ",anzahl)
    avg = summe / anzahl
    return avg

print("avg: ",mittelwert())  
