#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    int count = 0;

    getline(cin, line);

    for (int i = 1; i < line.size(); i++){
        if (line[i - 1] == ' ' && (line[i] == 'a' || line[i] == 'A')){
            count++;
        }
    }

    if (line[0] == 'a' || line[0] == 'A'){
        count++;
    }
    
    cout << "Кількість слів, що починаються на букву 'а': " << count << endl;

    return 0;
}
