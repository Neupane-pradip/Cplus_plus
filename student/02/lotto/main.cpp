#include <iostream>
#include <cmath> // For pow function

unsigned long int calculateCombinations(int totalBalls, int drawnBalls) {
    // Calculate the number of combinations (totalBalls choose drawnBalls)
    unsigned long int numerator = 1;
    unsigned long int denominator = 1;

    for (int i = 0; i < drawnBalls; ++i) {
        numerator *= (totalBalls - i);
        denominator *= (i + 1);
    }

    return numerator / denominator;
}

int main() {
    int totalBalls, drawnBalls;

    // Input the total number of lottery balls
    std::cout << "Enter the total number of lottery balls: ";
    std::cin >> totalBalls;

    // Input the number of drawn balls
    std::cout << "Enter the number of drawn balls: ";
    std::cin >> drawnBalls;

    // Check if the total number of balls is positive
    if (totalBalls <= 0) {
        std::cout << "The number of balls must be a positive number." << std::endl;
        return 1; // Terminate the program
    }

    // Check if the number of drawn balls is positive and within the valid range
    if (drawnBalls <= 0 || drawnBalls > totalBalls) {
        std::cout << "The number of balls must be a positive number, and the maximum number of drawn balls is the total amount of balls." << std::endl;
        return 1; // Terminate the program
    }

    // Calculate the probability of winning the jackpot
    unsigned long int combinations = calculateCombinations(totalBalls, drawnBalls);
    std::cout << "The probability of guessing all " << drawnBalls << " balls correctly is1/" << combinations << std::endl;

    return 0; // Program executed successfully
}
