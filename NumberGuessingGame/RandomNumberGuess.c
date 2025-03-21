#include <stdio.h>
#include <stdlib.h> // Standard library for memory allocation, process control, conversions, and others

#include <time.h>

int calculateScore(int guessCounter) { // Function to calculate score based on the number of attempts

    switch (guessCounter) { // Determine score based on the number of guesses

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

    srand(time(NULL)); // Seed the random number generator with the current time

    numberToGuess = rand() % 100; // Generate a random number between 0 and 99 for the user to guess

    printf("%d\n", numberToGuess); //for debuging

    while (guessCounter < chances) { // Loop until the user has used all chances

        guessCounter++;
        printf("Please Enter your Guess(1 to 100): "); // Prompt user for their guess

        scanf("%d", &myGuess);

        if (myGuess == numberToGuess) {
            myScore = calculateScore(guessCounter);
            printf("The number is %d and you found it right !! in the %d attempt\n", numberToGuess, guessCounter); // Display the correct number and attempt

            printf("Your score is: %d\n", myScore); // Display the user's score

            break;
        } else if (guessCounter >= chances) {
            printf("Oops sorry, The number is %d better luck next time\n", numberToGuess);
            break;
        } else if ((myGuess > numberToGuess) && (myGuess < 101)) {
            printf("Your guess is higher \n"); // Feedback if the guess is too high

        } else if ((myGuess < numberToGuess) && (myGuess > 0)) {
            printf("Your guess is lesser\n"); // Feedback if the guess is too low

        } else{
          printf("Number out of bounds\n"); // Feedback if the guess is out of bounds

        }
    }

    return 0;
}
