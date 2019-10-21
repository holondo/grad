#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "md5.h"

int main () {
    char opt[5];
    login user;
  
    Htab *tab = init_tab();
    while (scanf("%s",  opt) != EOF) { 	
        
        double ratio = (double) tab->n/ (double) tab->m;
        
		if (ratio >= 0.85)
			tab = create_tab(tab);

        if (strcmp(opt,"cad") == 0) {
			scanf("%s %s", user.name, user.pass);
			strcpy(user.pass, str2md5(user.pass, strlen(user.pass)));
            
            if (insert_tab (tab, user))
				printf("Cadastro realizado com sucesso\n");
			else 
				printf("Nome de usuario invalido\n");
            
        } else if (strcmp(opt,"aut") == 0) {
			scanf("%s %s", user.name, user.pass);
			strcpy(user.pass, str2md5(user.pass, strlen(user.pass)));
			
			if (search_tab(tab, user))
				printf("Nome de usuario ou senha invalidos");
			else
				printf("Autenticacao feita com sucesso");
			

		} else if (strcmp(opt,"del") == 0) {
			scanf("%s %s", user.name, user.pass);
			strcpy(user.pass, str2md5(user.pass, strlen(user.pass)));
			
			if (search_tab(tab, user))
				delete_tab(tab, user);
		}
		
		else 
			exib_tab(tab);
			
	}
}
