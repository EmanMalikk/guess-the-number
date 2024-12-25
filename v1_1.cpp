#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame() {
    int lower, upper, number, guess, attempts = 0;
    const int maxAttempts = 5;

    // Ask for range
    std::cout << "Enter the lower bound of the range: ";
    std::cin >> lower;
    std::cout << "Enter the upper bound of the range: ";
    std::cin >> upper;

    // Seed for random number generation
    std::srand(std::time(0));
    number = std::rand() % (upper - lower + 1) + lower;

    std::cout << "I have selected a number between " << lower << " and " << upper << ". You have " << maxAttempts << " attempts to guess it." << std::endl;

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
    char playAgain;

    do {
        playGame();
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;
    return 0;
}
