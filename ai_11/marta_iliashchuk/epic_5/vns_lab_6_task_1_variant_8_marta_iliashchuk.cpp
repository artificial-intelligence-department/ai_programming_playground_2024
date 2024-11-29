#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string result;
    char str[256];

    cout<<"Enter a string: ";
    gets(str);

    char* token = strtok(str, " "); 
    
    while (token != nullptr){
        bool isNumeric = true;
        for (int i = 0; token[i] != '\0'; i++){
            if (!isdigit(token[i])){
                isNumeric = false;
                result+=token;
                result+="_";
                break;
            }
        }
        token = strtok(nullptr, " ");
    }
    
    result.pop_back();

    cout<<"Changed string: "<<result<<endl;
    
    return 0;
}