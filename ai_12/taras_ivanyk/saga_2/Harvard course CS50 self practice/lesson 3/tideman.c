#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2){
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX){
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++){
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++){
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++){
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++){
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)){
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

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]){
    for(int i = 0; i < candidate_count; ++i){
        if(strcmp(candidates[i], name) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]){
    for(int i = 0; i < candidate_count; ++i){
        for(int j = i + 1; j < candidate_count; ++j){
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void){
    pair_count = 0;

    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j < candidate_count; j++){
            if(preferences[i][j] > preferences[j][i]){
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void){
    for(int i = 0; i < pair_count - 1; i++){           //Buble Sort
        for(int j = 0; j < pair_count - 1 - i; j++){

            int strength_curr = preferences[pairs[j].winner][pairs[j].loser];
            int strength_next = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            // strength_curr - містить кількість голосів відданих
            // кандидату winner перед кандидатом loser

            if(strength_curr > strength_next){
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void){
    for(int i = 0; i < pair_count; ++i){
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        bool visited[MAX] = {false};  // arr for checking cycles
        bool creates_cycle = false;

        if(locked[loser][winner] || loser == winner){
            creates_cycle = true;
        } else{
            for(int j = 0; j < candidate_count; j++){
                if(locked[loser][j] && !visited[j]){
                    visited[j] = true;

                    if(j == winner || locked[j][winner]){
                        creates_cycle = true;
                        break;
                    }
                }
            }
        }
        if(!creates_cycle){
            locked[winner][loser] = true;
        }
    }
}

void print_winner(void){

    for(int i = 0; i < candidate_count; i++){
        bool is_winner = true;

        for(int j = 0; j < candidate_count; j++){
            if(locked[j][i]){
                is_winner = false;
                break;
            }
        }
        if(is_winner){
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
