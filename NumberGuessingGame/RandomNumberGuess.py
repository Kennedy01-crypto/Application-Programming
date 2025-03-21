import random

# Welcome message to the user
print("Hi welcome to the game, This is a number guessing game.\nYou got 7 chances to guess the number. Let's start the game")

# Generate a random number between 0 and 99


number_to_guess = random.randrange(100)  # Random number to guess

# Total number of chances for the user


chances = 7
guess_counter =  0 

def calculate_score(guess_counter):
  # Calculate the score based on the guess counter.
  # The score decreases with the number of attempts taken to guess correctly.

  
  scores = {
    1: 100,
    2: 90,
    3: 80,
    4: 60,
    5: 40,
    6: 20,
    7: 5,
  }
  
  return scores.get(guess_counter, 0)  # Returns the score based on the guess counter, or 0 if not found.
  
# for debugging
# print(number_to_guess)

# Loop until the user has used all chances
while guess_counter < chances:
  # Increment the guess counter

  guess_counter += 1
  my_guess = int(input('Please Enter your Guess (1 to 100):'))  # User input for their guess
  
  if my_guess == number_to_guess:
    # Calculate the score based on the guess counter
    myScore = calculate_score(guess_counter)
    
    print(f'The number is {number_to_guess}\nYou found it in attempt {guess_counter}')  # Display the correct number and attempt in which it was achieved
    print(f'Your Score is: {myScore}')  # Display the user's score
    break
  elif guess_counter >= chances:
    print(f'Oops sorry, The number is {number_to_guess} better luck next time')
    break
  elif (my_guess > number_to_guess and my_guess <= 100):
    print("Your Guess is higher")  # Feedback if the guess is too high
  elif (my_guess < number_to_guess and my_guess >= 1):
    print("Your Guess is lower")  # Feedback if the guess is too low
  else:
    print("Number is not within the required range")  # Feedback if the guess is out of bounds
