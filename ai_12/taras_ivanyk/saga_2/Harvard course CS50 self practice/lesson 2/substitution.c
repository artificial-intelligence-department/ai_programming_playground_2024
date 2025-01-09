#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_key_valid(string key){
    if(strlen(key) != 26){
        return false;
    }
    for(int i = 0; i < strlen(key); ++i){
        if(!isalpha(key[i])){
            return false;
        }
    }

    for(int i = 0; i<25; ++i){
        for(int j = i + 1; j < 26;++j){
            if(toupper(key[i])== toupper(key[j])){
                return false;
            }
        }
    }
    return true;
}

string encrypt_message(string plaintext, string key){
    string ciphertext = plaintext;
    int n = strlen(plaintext);

    for(int i = 0; i < n; i++){
        if(isupper(plaintext[i])){
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if(islower(plaintext[i])){
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }
    return ciphertext;
}

int main(int argc, string argv[]){

    if(argc != 2){
        printf("Usage: ./substituion key \n");
        return 1;
    }

    string key = argv[1];

    if(!is_key_valid(key)){
        printf("Key must contain 26 characters, characters can't repeated an must be letters from ASCII");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");
    string ciphertext = encrypt_message(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
