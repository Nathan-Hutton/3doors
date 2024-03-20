#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,2);
    float correctWithSwitch = 0, correctNoSwitch = 0;
    int numTrials = 10000000;

    for (int i = 0; i < numTrials; i++)
    {
        int doorWithPrize = distrib(gen);
        int guess = distrib(gen);

        if (guess == doorWithPrize)
        {
            correctNoSwitch++;
            continue;
        }

        correctWithSwitch++;
    }

    // Print amount of times we got it right
    printf("Amount of times we got it right out of 10,000,000:\n");
    printf("Without switching: %.0f\n", correctNoSwitch);
    printf("With switching: %.0f\n", correctWithSwitch);
    printf("\nPercentages:\n");
    printf("Without switching: %.2f%%\n", (correctNoSwitch / numTrials) * 100);
    printf("With switching: %.2f%%\n", (correctWithSwitch / numTrials) * 100);
}
