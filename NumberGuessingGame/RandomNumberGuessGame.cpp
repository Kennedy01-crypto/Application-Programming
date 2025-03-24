#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Welcome message
    std::cout << "Hi welcome to the game, This is a number guessing game." << std::endl;
    std::cout << "You got 7 chances to guess the number. Let's start the game" << std::endl;

    // Seed the random number generator
    std::srand(std::time(0));
    int numberToGuess = std::rand() % 100; // Generating a random number between 0 and 99
    int chances = 7; // Number of chances
    int guessCounter = 0; // Counter for the number of guesses
    int myScore = 0; // Score for each guess
    // std::cout << numberToGuess << std::endl; //for debugging purposes

    // Loop for the guessing game
    while (guessCounter < chances) {
        guessCounter++; // Incrementing the guess counter
        int myGuess;
        std::cout << "Please Enter your Guess (from 1 to 100): ";
        std::cin >> myGuess; // Reading user input

        // Checking if the guess is correct
        if (myGuess == numberToGuess) {
            // Calculate the score based on the remaining chances
            switch (guessCounter) {
                case 1:
                    myScore = 100;
                    break;
                case 2:
                    myScore = 90;
                    break;
                case 3:
                    myScore = 80;
                    break;
                case 4:
                    myScore = 60;
                    break;
                case 5:
                    myScore = 40;
                    break;
                case 6:
                    myScore = 20;
                    break;
                case 7:
                    myScore = 5;
                    break;
                default:
                    myScore = 0;
                    break;
            }
            std::cout << "The number is " << numberToGuess << " and you found it right !! in the " << guessCounter << " attempt" << std::endl;
            std::cout << "your score is " << myScore << std::endl;
            break; // Exiting the loop if the guess is correct
        }
        // Checking if the user has used all chances
        else if (guessCounter >= chances) {
            std::cout << "Oops sorry, The number is " << numberToGuess << " better luck next time" << std::endl;
        }
        // Providing feedback if the guess is too high
        else if (myGuess > numberToGuess && myGuess <= 100) {
            std::cout << "Your guess is higher" << std::endl;
        }
        // Providing feedback if the guess is too low
        else if (myGuess < numberToGuess && myGuess >= 1) {
            std::cout << "Your guess is lesser" << std::endl;
        } else {
            std::cout << "Enter Number from 1 to 100 " << std::endl;
        }
    }
    return 0;
}
