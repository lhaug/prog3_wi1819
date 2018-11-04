#include <stdio.h>

int rot13(int zahl, int grenze){
	return ((zahl-grenze+13)%26+grenze);
}

int main(void){
	char eing[100];
	int i;
	char ascii;
	
	while(fgets(eing, sizeof(eing),stdin) != NULL){
		for(i=0; i<100;i++){
			if( eing[i] == '\0') break;
			ascii = eing[i];
			
			if ((ascii >= 'A')&&(ascii <= 'Z')){ /* entspricht 65 und 90*/
				putchar(rot13(ascii, 65));
			}else if((ascii >= 'a')&&(ascii <= 'z')){ /* entspricht 97 und 122*/
				putchar(rot13(ascii, 97));
			}else{
				putchar(ascii);
			}
		} 
	}
	return 0;
}


