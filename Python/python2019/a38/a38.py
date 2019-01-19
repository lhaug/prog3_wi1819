'''
Created on 15.01.2019

@author: Lea
'''
def permutationen(seq):
    
    if seq == []:
        yield [];
    else:
        for s in seq:
            for p in permutationen(seq[1:]):
                yield [s]+p
            seq = seq[1:]+[seq[0]]
          

counter = 0
for p in permutationen([1, 2, 3,4,5]):
    counter+=1
    print(p)
print(counter)