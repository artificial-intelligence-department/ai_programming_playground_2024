#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<string> libary = {"Переслідування Аделіни", "Інститут", "Не озирайся і мовчи", "Ветролом"};
    vector<bool> libary_status = {};
    int choice, choice2;
    for(string k: libary){
        libary_status.push_back(1);
    }
    
    
    while(1){
        cout << "Бібліотека книг:\n";
        for(int i = 0; i<libary_status.size(); i++){
            if(libary_status[i] == 1){
                cout << "\t" << i+1 << " "<< libary[i] << ";\n";
            }
        }
        cout << "Ваші книги з цієї бібліотеки:\n";
        for(int i = 0; i<libary_status.size(); i++){ 
            if(libary_status[i] == 0){
                cout << "\t" << i+1 << " " << libary[i] << ";\n";
            }
        }
        cout 
        << "\nФункціонал: \n"
        << "\t1 Взяти книгу\n"
        << "\t2 Повернути книгу\n"
        << "\t3 Вийти з програми\n";
        cin >> choice;

        if (choice == 1){
            do{
                cout << "Введіть номер книги яку хочете взяти: ";
                cin >> choice2;
                if (libary_status[choice2-1] == 1){
                    libary_status[choice2-1] = 0;
                    cout << "##########################################################" << endl;
                    break;
                }
                else if (choice2 > libary.size()){
                    cout << "Такої книги тут нема\n" << endl;
                }
                else{
                    cout << "Цю книгу вже взяли\n"<< endl;
                }
            }while(1);
        }

        else if (choice == 2){
            do{
                cout << "Введіть номер книги яку хочете повернути: ";
                cin >> choice2;
                
                if (choice2 > libary.size()){
                    cout << "Такої книги тут не було\n" << endl;
                }

                else if (libary_status[choice2-1] == 0){
                    libary_status[choice2-1] = 1;
                    cout << "##########################################################" << endl;
                    break;
                }
                else{
                    cout << "Ця книга вже є\n" << endl;
                }
            }while (1);

        }
        else if (choice == 3){
            break;
        }

    }

}
