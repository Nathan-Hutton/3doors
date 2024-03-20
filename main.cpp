#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,2);

    int guess;
    int doorWithPrize;
    float correctWithSwitch = 0, correctNoSwitch = 0;

    for (int i = 0; i < 10000000; i++)
    {
        doorWithPrize = distrib(gen);
        guess = distrib(gen);

        int doorToReveal;
        for (int j = 0; j <= 2; j++)
        {
            if (j == guess || j == doorWithPrize)
                continue;

            doorToReveal = j;
            break;
        }

        for (int j = 0; j <= 2; j++)
        {
            if (j == guess || j == doorToReveal)
                continue;

            guess = j;
            break;
        }

        if (guess == doorWithPrize)
            correctWithSwitch++;
    }

    for (int i = 0; i < 10000000; i++)
    {
        doorWithPrize = distrib(gen);
        guess = distrib(gen);
        if (guess == doorWithPrize)
            correctNoSwitch++;
    }

    // Print amount of times we got it right
    printf("Amount of times we got it right out of 10,000,000:\n");
    printf("Without switching: %.0f\n", correctNoSwitch);
    printf("With switching: %.0f\n", correctWithSwitch);
    printf("\nPercentages:\n");
    printf("Without switching: %.2f%%\n", (correctNoSwitch / 10000000.0) * 100);
    printf("With switching: %.2f%%\n", (correctWithSwitch / 10000000.0) * 100);
}
