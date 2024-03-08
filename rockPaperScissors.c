#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int decide(int pers, int comp) {
    if (pers == comp) {
        return -1; // Tie
    } else if ((pers == 1 && comp == 3) || (pers == 2 && comp == 1) || (pers == 3 && comp == 2)) {
        return 1; // User wins
    } else {
        return 0; // User loses
    }
}

char * choiceResult(int input) {
    switch(input){
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
    }
}

int main(){
    int choice;
    int random;

    printf("Hello! Welcome to Rock, Paper, Scissors!\n");
    printf("\nOptions:\n1. Rock\n2. Paper\n3. Scissors\n");
    scanf("%d", &choice);
    srand(time(NULL));
    random = rand() % 3 + 1;
    int result = decide(choice, random);

    const char *userChoice = choiceResult(choice);
    const char *compChoice = choiceResult(random);

    printf("%s VS %s\n", userChoice, compChoice);

    switch(result){
        case -1:
            printf("YOU DREW!\n");
            break;
        case 0:
            printf("YOU LOST!\n");
            break;
        case 1:
            printf("YOU WON!");
            break;
    }

    return 0;
}
