import random

print("Hi welcome to the game, This is a number guessing game.\nYou got 7 chances to guess the number. Let's start the game")

number_to_guess = random.randrange(100)

chances = 7
guess_counter =  0 

def calculate_score(guess_counter):
  # Calculate the score based on the guess counter.
  
  scores = {
    1: 100,
    2: 90,
    3: 80,
    4: 60,
    5: 40,
    6: 20,
    7: 5,
  }
  
  return scores.get(guess_counter, 0) #returns the value if the key exists, otherwise 0.
  
# for debugging
# print(number_to_guess)

while guess_counter < chances:
  guess_counter += 1
  my_guess = int(input('Please Enter your Guess (1 to 100):'))
  
  if my_guess == number_to_guess:
    #calculate the score based on the guess_counter
    myScore = calculate_score(guess_counter)
    
    print(f'The number is {number_to_guess}\nYou found it in attenpt {guess_counter}')
    print(f'Your Score is: {myScore}')
    break
  elif guess_counter >= chances:
    print(f'Oops sorry, The number is {number_to_guess} better luck next time')
    break
  elif (my_guess > number_to_guess and my_guess <= 100):
    print("Your Guess is higher")
  elif (my_guess < number_to_guess and my_guess >= 1):
    print("Your Guess is lower")
  else:
    print("Number is not within the required range")