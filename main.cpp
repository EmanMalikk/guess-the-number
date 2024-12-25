#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame() {
    int number, guess, attempts = 0;
    const int maxAttempts = 5;

    // Seed for random number generation
    std::srand(std::time(0));
    number = std::rand() % 100 + 1; // Random number between 1 and 100

    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. You have " << maxAttempts << " attempts to guess it." << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess == number) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
            return;
        } else if (guess < number) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    std::cout << "Sorry, you've used all " << maxAttempts << " attempts. The correct number was " << number << "." << std::endl;
}

int main() {
    playGame();
    return 0;
}
