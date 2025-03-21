using System; // Importing the System namespace for basic functionalities

class RandomNumberGuess {
    static int Main() {
        // Welcome message
        Console.WriteLine("Hi welcome to the game, This is a number guessing game.");
        Console.WriteLine("You got 7 chances to guess the number. Let's start the game");

        Random random = new Random(); // Creating an instance of Random
        int numberToGuess = random.Next(100); // Generating a random number between 0 and 99
        int chances = 7; // Number of chances
        int guessCounter = 0; // Counter for the number of guesses
        int myScore = 0;//Score for each guess
        // Console.WriteLine($"{numberToGuess}"); //for debugging purposes
        // Loop for the guessing game
        while (guessCounter < chances) {
            guessCounter++; // Incrementing the guess counter
            Console.Write("Please Enter your Guess (from 1 to 100): ");
            int myGuess = Convert.ToInt32(Console.ReadLine()); // Reading user input

            // Checking if the guess is correct
            if (myGuess == numberToGuess) {
                
                //calculate the score based on the remaining chances
                switch(guessCounter){
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
                Console.WriteLine($"The number is {numberToGuess} and you found it right !! in the {guessCounter} attempt");
                Console.WriteLine($"your score is {myScore}");
                break; // Exiting the loop if the guess is correct
            } 
            // Checking if the user has used all chances
            else if (guessCounter >= chances) {
                Console.WriteLine($"Oops sorry, The number is {numberToGuess} better luck next time");
            } 
            // Providing feedback if the guess is too high
            else if (myGuess > numberToGuess && myGuess <= 100) {
                Console.WriteLine("Your guess is higher");
            } 
            // Providing feedback if the guess is too low
            else if (myGuess < numberToGuess && myGuess >= 1) {
                Console.WriteLine("Your guess is lesser");
            }
            else{
                Console.WriteLine("Enter Number from 1 to 100 ");
            }
        }
        return 0;
    }
}
