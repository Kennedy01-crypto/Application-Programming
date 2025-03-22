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
        int myScore = 0; //Score for each guess
        // System.out.println(numberToGuess);//for debuging

        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for user input

        // Loop for the guessing game
        while (guessCounter < chances) {
            guessCounter++; // Incrementing the guess counter
            System.out.print("Please Enter your Guess: ");
            int myGuess = scanner.nextInt(); // Reading user input

            // Checking if the guess is correct
            if (myGuess == numberToGuess) {
                //calculate the score based on the remaining chances
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
                System.out.println("The number is " + numberToGuess + " and you found it right !! in the attempt " + guessCounter );
                System.out.println("Your score is " + myScore + " points");
                break; // Exiting the loop if the guess is correct
            } 
            // Checking if the user has used all chances
            else if (guessCounter >= chances) {
                System.out.println("Oops sorry, The number is " + numberToGuess + " better luck next time");
                System.out.println("Your score is " + myScore + " points");
                break; // Exiting the loop if the user has used all chances
            } 
            // Providing feedback if the guess is too high
            else if ((myGuess > numberToGuess) && (myGuess <= 100)){
                System.out.println("Your guess is higher");
            } 
            // Providing feedback if the guess is too low
            else if ((myGuess < numberToGuess) && (myGuess > 0)) {
                System.out.println("Your guess is lesser");
            }
            else {
                System.out.println("Number is out of bounds \nEnter a number between 1 and 100");
            }
        }
        scanner.close(); // Closing the scanner
        System.exit(0);//Exit with status code 0 (success)
    }
}
