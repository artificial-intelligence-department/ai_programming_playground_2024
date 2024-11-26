#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str_in;
    cin >> str_in;

    string str_out;
    int counter = 1;
    char current_element;
    string str_counter;

    // cout << str_in.length() << "\n";

    for (int i = 1; i <= str_in.length(); i++)
    {   
        if (str_in.length() == 1)
        {
            str_out += str_in[0];
            break;
        }
        
        if (i != str_in.length())
        {
            current_element = str_in[i-1];
            if (str_in[i-1] == str_in[i])
            {
                ++counter;
            }
            else
            {
                str_out += current_element;
                if (counter != 1){
                    str_counter = to_string(counter);
                    str_out += str_counter;
                }
                counter = 1;
            }
        }
        else
        {
            current_element = str_in[i-1];
            str_out += current_element;
            if (counter != 1){
                str_counter = to_string(counter);
                str_out += str_counter;
            }
            counter = 1;
        }
             
    }
    cout << str_out << endl;
}