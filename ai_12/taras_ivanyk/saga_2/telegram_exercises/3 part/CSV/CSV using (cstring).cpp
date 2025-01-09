#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string input = "Please,split,this,string,by,commas";
    char* split = strdup(input.c_str());  // strdup allocates dynamic memory
                                           // for the new string
    // c_str - like converts C++ to C
    char* token;
    cout << "Splitted string: \n";
    token = strtok(split, ",");
    while(token){
        cout << token << endl;
        token = strtok(NULL, ",");
    }
    free(split); // free dynamic memory
    return 0;
}

// MORE ADVANCED VARIANT:

// #include <iostream>
// #include <sstream>
// using namespace std;

// int main() {
//     string input = "Please,split,this,string,by,commas";
//     stringstream ss(input);
//     string token;

//     cout << "Splitted string: \n";
//     while (getline(ss, token, ',')) {
//         cout << token << endl;
//     }

//     return 0;
// }