#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateScore(int guessCounter) {
    switch (guessCounter) {
        case 1: return 100;
        case 2: return 90;
        case 3: return 80;
        case 4: return 60;
        case 5: return 40;
        case 6: return 20;
        case 7: return 5;
        default: return 0;
    }
}

int main() {
    int numberToGuess, chances = 7, guessCounter = 0, myGuess, myScore;

    printf("Hi welcome to the game, This is a number guessing game.\n");
    printf("You got 7 chances to guess the number. Let's start the game\n");

    srand(time(NULL)); // Seed the random number generator
    numberToGuess = rand() % 100; // Generate a random number between 0 and 99
    printf("%d\n", numberToGuess); //for debuging

    while (guessCounter < chances) {
        guessCounter++;
        printf("Please Enter your Guess(1 to 100): ");
        scanf("%d", &myGuess);

        if (myGuess == numberToGuess) {
            myScore = calculateScore(guessCounter);
            printf("The number is %d and you found it right !! in the %d attempt\n", numberToGuess, guessCounter);
            printf("Your score is: %d\n", myScore);
            break;
        } else if (guessCounter >= chances) {
            printf("Oops sorry, The number is %d better luck next time\n", numberToGuess);
            break;
        } else if ((myGuess > numberToGuess) && (myGuess < 101)) {
            printf("Your guess is higher \n");
        } else if ((myGuess < numberToGuess) && (myGuess > 0)) {
            printf("Your guess is lesser\n");
        } else{
          printf("Number ot of bounds\n");
        }
    }

    return 0;
}