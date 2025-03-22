const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Welcome message
console.log("Hi welcome to the game, This is a number guessing game.");
console.log(
  "You have 7 chances to guess the number, which is between 0 and 99. Let's start the game!"
);

// Generating a random number between 0 and 99
const numberToGuess = Math.floor(Math.random() * 100);
const totalChances = 7; // Number of chances
let guessCounter = 0; // Counter for the number of guesses
let myScore = 0; // Score for each guess

function askForGuess() {
  if (guessCounter < totalChances) {
    guessCounter++;
    readline.question(
      `Please Enter your Guess (Attempt ${guessCounter}): `,
      (answer) => {
        const myGuess = parseInt(answer, 10);

        if (isNaN(myGuess) || myGuess < 0 || myGuess > 99) {
          console.log("Invalid input. Please enter a number between 0 and 99.");
          guessCounter--; // Decrement counter as it was an invalid guess
          askForGuess(); // Ask again
          return;
        }

        if (myGuess === numberToGuess) {
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
          console.log(
            `Congratulations! The number is ${numberToGuess} and you guessed it correctly in attempt ${guessCounter}!`
          );
          console.log(`Your score is ${myScore} points.`);
          readline.close();
        } else if (myGuess > numberToGuess) {
          console.log("Your guess is higher.");
          console.log(
            `You have ${totalChances - guessCounter} chances remaining.`
          );
          askForGuess();
        } else if (myGuess < numberToGuess) {
          console.log("Your guess is lower.");
          console.log(
            `You have ${totalChances - guessCounter} chances remaining.`
          );
          askForGuess();
        }
      }
    );
  } else {
    console.log(
      `Oops, you've run out of chances! The number was ${numberToGuess}.`
    );
    console.log(`Your final score is ${myScore} points.`);
    readline.close();
  }
}

askForGuess();
