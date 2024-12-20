#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool is_key_valid(int key){
    if(key < 0 || key > 26){
        return false;
    }
    return true;
}

string encrypt_message(string plaintext, int key){
    string ciphertext = plaintext;
    int n = strlen(plaintext);

    bool to_up_or_low = false;

    for(int i = 0; i < n; ++i){

        if(islower(ciphertext[i])){
            to_up_or_low = false;
        } else{
            to_up_or_low = true;
        }

        ciphertext[i] = plaintext[i] + (key % 26);
        if(ciphertext[i] > 122){
            ciphertext[i] -= 26;
        } else if(ciphertext[i] < 65){
            ciphertext[i] += 26;
        }
        if(to_up_or_low){
            ciphertext[i] = toupper(ciphertext[i]);
        } else{
            ciphertext[i] = tolower(ciphertext[i]);
        }
    }
    return ciphertext;
}

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key \n");
        return 1;
    }

    int key = atoi(argv[1]);
    is_key_valid(key);

    string plaintext = get_string("plaintext: \n");

    string ciphertext = encrypt_message(plaintext, key);
    printf("ciphertext: %s", ciphertext);

    printf("\n");

    return 0;
}
