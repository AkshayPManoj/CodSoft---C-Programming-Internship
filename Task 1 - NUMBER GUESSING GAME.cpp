//Task 1 - NUMBER GUESSING GAME
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    // Loop until the user guesses the correct number
    while (userGuess != numberToGuess) 
    {
        // Read the user's guess
        std::cin >> userGuess;

        // Provide feedback based on the user's guess
        if (userGuess < numberToGuess) 
        {
            std::cout << "Too low! Try again: ";
        } 
        else if (userGuess > numberToGuess) 
        {
            std::cout << "Too high! Try again: ";
        } 
        else 
        {
            std::cout << "Congratulations! You've guessed the number!" << std::endl;
        }
    }

    return 0;
}
