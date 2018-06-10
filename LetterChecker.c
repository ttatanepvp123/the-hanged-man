#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//local include
#include "define.h"
#include "LetterChecker.h"
#include "File.h"

int LetterChecker(char lettre){
    static int debug = 0;
    int resultat = 0;
    int i = 0;
    static char phrase[STRING_ALLOC] = "unkown";
    static char DisplayPhrase[25];

    if (lettre == 1) {
        printf("%s : ", phrase);
    }
    
    if (!strcmp(phrase,"unkown")){
        DicoSelectPhrase(phrase);
    }
    

    if (debug == 0) {
        for(i = 0; i < strlen(phrase); i++)
        {
            
            if (i + 1 == strlen(phrase)){
                DisplayPhrase[i] = '\n';
            } else {
                DisplayPhrase[i] = '*';
            }
        }
    }
    
    for(i = 0; i < strlen(phrase); i++){
        
        if (lettre == phrase[i] || lettre + 32 == phrase[i] || lettre - 32 == phrase[i]) {
            DisplayPhrase[i] = phrase[i];
            resultat = 1;
        }
        
    }
    
    if(!strcmp(phrase,DisplayPhrase)) {
        return 3;
    } else {
        printf("%s", DisplayPhrase);
    }
    debug++;
    if(resultat == 1){
        return 1;
    } 
    else
    {
        return 0;
    }
    
}