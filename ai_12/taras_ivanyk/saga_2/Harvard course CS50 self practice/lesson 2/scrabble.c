#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compare_word(string word){
    int score = 0;
    for(int i = 0; i < strlen(word); ++i){
        if(isupper(word[i])){
            score += scores[word[i] - 'A'];
        } else if(islower(word[i])){
            score += scores[word[i] - 'a'];
        }
    }
    return score;
}

int main(void){
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    if(compare_word(word1) > compare_word(word2)){
        printf("Player 1 wins! \n");
    } else if(compare_word(word1) < compare_word(word2)){
        printf("Player 2 wins! \n");
    } else{
        printf("Tie!\n");
    }
    return 0;
}
