'''
Created on 15.01.2019

@author: Lea
'''

text = [line.split("\n")[0].split(";") for line in open("text.txt")]
    
#print(text)


#1
a = sorted([ wohnort for anrede, nachname, vorname, gehalt, wohnort in text if anrede=="Herr"])
print(a)

#2
b = sum([int(gehalt) for anrede, nachname, vorname, gehalt, wohnort in text if anrede=="Frau"])
print(b)

#3 
c = max([(wohnort,gehalt) for anrede, nachname, vorname, gehalt, wohnort in text if vorname[0]=="J"], key = lambda x: x[-1])[0]

print(c)

#4
d = ["{} {} bekommt mehr, als {} verdient!".format(anrede, nachname, "er" if anrede=="Herr" else "sie") for anrede, nachname, vorname, gehalt, wohnort in text if int(gehalt) >= 100000]
print(d)

vornamen = [(anrede, vorname, gehalt) for anrede, nachname, vorname, gehalt, wohort in text] 
y = min(vornamen, key=lambda x: x[-1])