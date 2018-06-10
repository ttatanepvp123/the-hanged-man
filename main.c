#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//local include
#include "define.h"
#include "LetterChecker.h"
#include "File.h"

int checkWinAndLousses(int Life);
int mainGame();


int main(int argc, char const *argv[]){//the smallest main in the world O_O
    int QuitGame = 0;
    while(QuitGame == 0){
        QuitGame = checkWinAndLousses(mainGame());
    }
    return 0;
}

int checkWinAndLousses(int Life){
    if (Life == 0) {
        printf(MSG_DEAD);
        printf(MSG_DEAD);
        LetterChecker((char) 1);
        getchar();
        return 1;
    } else if(Life == -1){
        printf(MSG_WIN);
        getchar();
        getchar();
        return 1;
    }
    
    return 0;
}

int mainGame(){
    static char Letter;
    static int Life = 20;
    static int tmp = 0;
    printf(MSG_BEFORE_DEAD,Life);
    printf(PROMPT_LETTER_REQUEST);
    scanf("%c", &Letter);
    tmp = LetterChecker(Letter);
    if (tmp == 0) {
        Life--;
    } else if (tmp == 3) {
        return -1;
    }
    
    scanf("%c", &Letter);//for delete "\n" in stdin
    return Life;
}
