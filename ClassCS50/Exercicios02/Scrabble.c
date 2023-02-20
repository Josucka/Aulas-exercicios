#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int total = 0; int t = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isalpha(word[i]) && islower(word[i]))
        {
            t = word[i] - 97;
            total += POINTS[t];
        }
        else if (isalpha(word[i]) && isupper(word[i]))
        {
            t = word[i] - 65;
            total += POINTS[t];
        }
    }

    return total;
}