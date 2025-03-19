using System; // Importing the System namespace for basic functionalities

class RandomNumberGuess {
    static void Main() {
        // Welcome message
        Console.WriteLine("Hi welcome to the game, This is a number guessing game.");
        Console.WriteLine("You got 7 chances to guess the number. Let's start the game");

        Random random = new Random(); // Creating an instance of Random
        int numberToGuess = random.Next(100); // Generating a random number between 0 and 99
        int chances = 7; // Number of chances
        int guessCounter = 0; // Counter for the number of guesses

        // Loop for the guessing game
        while (guessCounter < chances) {
            guessCounter++; // Incrementing the guess counter
            Console.Write("Please Enter your Guess: ");
            int myGuess = Convert.ToInt32(Console.ReadLine()); // Reading user input

            // Checking if the guess is correct
            if (myGuess == numberToGuess) {
                Console.WriteLine($"The number is {numberToGuess} and you found it right !! in the {guessCounter} attempt");
                break; // Exiting the loop if the guess is correct
            } 
            // Checking if the user has used all chances
            else if (guessCounter >= chances) {
                Console.WriteLine($"Oops sorry, The number is {numberToGuess} better luck next time");
            } 
            // Providing feedback if the guess is too high
            else if (myGuess > numberToGuess) {
                Console.WriteLine("Your guess is higher");
            } 
            // Providing feedback if the guess is too low
            else {
                Console.WriteLine("Your guess is lesser");
            }
        }
    }
}
