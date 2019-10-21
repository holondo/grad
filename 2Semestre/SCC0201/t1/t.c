#include <stdio.h>
#include <stdlib.h>

int compara(unsigned char chave[], unsigned char bloco[]) {
	unsigned char blocoAux = bloco[3];
	bloco[3] /= 16;
	
	for (int x = 0; x < 4; x++) 
		if (chave[x] != bloco[x]) {
			bloco[3] = blocoAux;
			return 0;
		}
	
	bloco[3] = blocoAux;	
	return 1;
				
}



int main () {
	FILE *p = NULL;
	int x = 0;
	char img[8];
	unsigned char bloco[512], chave[4] = {0xff, 0xd8, 0xff, 0xe};
	
	
	while (fread(bloco, 512, 1, stdin) != 0) {		
			
		if (compara(chave,bloco)) {
			
			if (p != NULL)
				fclose(p);
			
			sprintf(img, "%03d.jpg", x++);
			p = fopen (img,"w");
		}
		
		if (p != NULL)
			fwrite(bloco, 512, 1, p);
		
		
		
	}
	if (x == 0)
		printf("Could not find pictures\n");
		
	return 0;
}
