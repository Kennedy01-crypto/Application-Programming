import java.util.Random;  // Importing the Random class for generating random numbers
import java.util.Scanner; // Importing the Scanner class for user input

public class RandomNumberGuess {
    public static void main(String[] args) {
        // Welcome message
        System.out.println("Hi welcome to the game, This is a number guessing game.");
        System.out.println("You got 7 chances to guess the number. Let's start the game");

        Random random = new Random(); // Creating an instance of Random
        int numberToGuess = random.nextInt(100); // Generating a random number between 0 and 99
        int chances = 7; // Number of chances
        int guessCounter = 0; // Counter for the number of guesses

        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for user input

        // Loop for the guessing game
        while (guessCounter < chances) {
            guessCounter++; // Incrementing the guess counter
            System.out.print("Please Enter your Guess: ");
            int myGuess = scanner.nextInt(); // Reading user input

            // Checking if the guess is correct
            if (myGuess == numberToGuess) {
                System.out.println("The number is " + numberToGuess + " and you found it right !! in the " + guessCounter + " attempt");
                break; // Exiting the loop if the guess is correct
            } 
            // Checking if the user has used all chances
            else if (guessCounter >= chances) {
                System.out.println("Oops sorry, The number is " + numberToGuess + " better luck next time");
            } 
            // Providing feedback if the guess is too high
            else if (myGuess > numberToGuess) {
                System.out.println("Your guess is higher");
            } 
            // Providing feedback if the guess is too low
            else {
                System.out.println("Your guess is lesser");
            }
        }

        scanner.close(); // Closing the scanner
    }
}
