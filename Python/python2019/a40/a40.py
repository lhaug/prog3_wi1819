'''
Created on 19.01.2019

@author: Lea
'''
class Messreihe():
    
    def __init__(self, strings=None):
        self.messreihe = []
        if strings != None:
            for i in strings:
                self.messreihe = self.messreihe+[i]
                
    def __print__(self):
        return self.messreihe
    
    
mr = Messreihe(open("messwerte.csv"))

print(mr)
            
            
        