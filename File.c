#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//local include
#include "define.h"
#include "LetterChecker.h"
#include "File.h"

void DicoSelectPhrase(char Mot[STRING_ALLOC]){
    FILE *dico;
    dico = fopen("dico.txt","r");
    char str[STRING_ALLOC];
  
    int i = 0;
  
    if (dico != NULL) {
        while(!feof(dico)){
            fgets(str, STRING_ALLOC-1, dico);
            i++;
        }
        rewind(dico);
        srand(time(NULL));
        int tmp = rand() % i;
 
 		for(size_t j = 0; j <= tmp; j++)
        {
        	fgets(str, STRING_ALLOC - 1, dico);
        }
      	strcpy(Mot, str);
    } else{
        fprintf(stderr,MSG_ERROR_FILE_NOT_ACCES);
    }
    
    fclose(dico);
}