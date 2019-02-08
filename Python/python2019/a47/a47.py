'''
Created on 08.02.2019

@author: Lea
'''
import re

date_pattern = re.compile('^((0[1-9])|([1-2][0-9])|(3[0-1]))(\.)((0[1-9])|(1[0-2]))(\.)([0-9]{4})$')
match = date_pattern.match('01.12.2018').group()
print(match)

money_pattern = re.compile('^([0-9]{1,3})(\.[0-9]{3})*(,[0-9]{2})?( EUR)?$')
match2 = money_pattern.match('17.342.915,56 EUR').group()
print(match2)

tel_pattern = re.compile('^((\+[1-9]{2} )|(00[1-9]{2} )|(0))([0-9]+((( )|(/)|(-))[0-9][0-9]+)*)$')
match3 = tel_pattern.match('+49 1525-40/92 699').group()
print(match3)