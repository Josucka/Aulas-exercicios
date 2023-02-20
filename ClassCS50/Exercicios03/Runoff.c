#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int Preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct {
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool isTie(int minVotes);
void eliminate(int minVotes);

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: Runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES) {
        printf("Maximum number of candidates is %i\n ", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;

    }

    voter_count = get_int("Number of votes: ");
    if (voter_count > MAX_VOTERS) {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    while (true) {
        tabulate();

        bool won = print_winner();
        if (won) {
            break;
        }

        int min = find_min();
        bool tie = isTie(min);
        if (tie) {
            for (int i = 0; i < candidate_count; i++) {
                if (!candidates[i].eliminated) {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++) {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            Preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void eliminate(int minVotes) {
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].eliminated == false && candidates[i].votes == minVotes) {
            candidates[i].eliminated = true;
        }
    }
    return;
}

bool isTie(int minVotes) {
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].eliminated == false && candidates[i].votes != minVotes) {

        }
        return false;
    }
    return true;
}


int find_min(void) {
    int minVotes = voter_count;

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].eliminated == false && candidates[i].votes > minVotes) {
            minVotes = candidates[i].votes;
        }
    }
    return 0;
}

bool print_winner(void) {
    for (int i = 0; i < candidate_count; i++) {
        string most = candidates[i].name;
        if (candidates[i].votes > voter_count / 2) {
            printf("Winner: %s\n", most);
        }
    }
    return false;
}

void tabulate(void) {
    for (int i = 0; i < voter_count; i++) {
        for (int j = 0; j < candidate_count; i++) {
            if (candidates[i].eliminated == false) {
                candidates[Preferences[i][j]].votes++;
            }
        }
    }
    return;
}