#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

int Preferences[MAX][MAX];
bool Locked[MAX][MAX];

typedef struct {
    int winner;
    int loser;
}
pair;

string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int candidate_count;
int pair_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycles(int winner, int loser);


int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: Tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            Locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++) {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;

}

bool vote(int rank, string name, int ranks[]) {
    for (int i = 0; i < candidate_count; i++) {
        if (!strcmp(candidates[i], name)) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[]) {
    for (int i = 0; i < candidate_count; i++) {
        int highest_vote = ranks[i];

        for (int j = 1; j < candidate_count - i; j++) {
            int lowest_vote = ranks[i + j];

            Preferences[highest_vote][lowest_vote]++;
        }
    }
}

void add_pairs(void) {
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (Preferences[i][j] > Preferences[j][i]) {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void) {
    for (int i = 0; i < pair_count; i++) {
        for (int j = 1; j < pair_count; j++) {
            if (Preferences[pairs[i].winner][pairs[i].loser] < Preferences[pairs[j].winner][pairs[j].loser]) {
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

void lock_pairs(void) {
    for (int i = 0; i < pair_count; i++) {
        if (!cycles(pairs[i].winner, pairs[i].loser)) {
            Locked[pairs[i].winner][pairs[i].loser] = true;
        }

        if (!cycles(pairs[i].winner, pairs[i].loser) && pairs[0].winner != pairs[i].loser) {
            Locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

void print_winner(void) {
    for (int i = 0; i < candidate_count; i++) {
        bool isLoser = false;
        for (int j = 0; j < candidate_count; j++) {
            if (Locked[j][i]) {
                isLoser = true;
                break;
            }
        }

        if (isLoser) {
            continue;
        }

        if (!isLoser) {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

bool cycles(int winner, int loser) {
    if (Locked[loser][winner] == true) {
        return true;
    }

    for (int i = 0; i < candidate_count; i++) {
        if (Locked[i][winner]) {
            return cycles(i, loser);
        }
    }
    return false;
}