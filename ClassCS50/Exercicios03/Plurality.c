#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define MAX 9

typedef struct {
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: Plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates id %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int votes_count = get_int("Number of Votes: ");

    for (int i = 0; i < votes_count; i++) {
        string name = get_string("Vote: ");

        if (!vote(name)) {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void) {
    int max = 0;
    int m = 0;
    string maxv;

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > max) {
            max = candidates[i].votes;
            maxv = candidates[i].name;
            printf("%s\n", maxv);
        }

        if ((candidates[i].votes == max) && ((strcmp(candidates[i].name, maxv) != 0))) {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}