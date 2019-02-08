#include <stdio.h>
#include <string.h>
#include "a4.h"

void schwabify(char *input, char output[]){
  char* akt = input;
  char* test;
  char* out = output;
  while(*akt!='\0'){
    /*verdacht pruefen*/
    test = akt;
    if(*akt == '.'){
      strcpy(out, ", woisch?");
      out = out+9;
      akt++;
    }else if( (*akt=='h')&&(*(test+1)=='a')&&(*(test+2)=='l')&&(*(test+3)=='t') ){
      strcpy(out, "heb");
      out = out+3;
      akt = akt+4;
    }else if( (*akt == 'i')&&(*(test+1)=='s')&&(*(test+2)=='t') ){
      strcpy(out, "isch");
      out = out+4;
      akt = akt+3;
    }else{
      /*kein ersetzen*/
      *out = *akt;
      out++;
      akt++;
    }
  }
  *out = '\0'; 
}
