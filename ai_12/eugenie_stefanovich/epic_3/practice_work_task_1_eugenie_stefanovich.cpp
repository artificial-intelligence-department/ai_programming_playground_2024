#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string wid;
    vector<string> BwB = {"B1", "B2", "B3", "B4", "B5", "B6"};
    vector<string> inv;

  
    for (const string& d : BwB) 
        cout << d << " ";
    
    while (wid != "yes" && wid != "Yes") {
        cout << endl << "Ви хочете вийти з бібліотеки? (Yes/No)" << endl;
        cin >> wid;

        if (wid == "No" || wid == "no") {
            cout << "Ви хочете взяти книгу чи покласти? (take/put)" << endl;
            cin >> wid;

            if (wid == "take" || wid == "Take") {
                cout << "Виберіть книгу зі списку: " << endl;
                
                for (const string& d : BwB) 
                    cout << d << " ";
                cout << endl;

                cin >> wid;

    
                auto it = find(BwB.begin(), BwB.end(), wid);
                if (it != BwB.end()) {
                    BwB.erase(it);
                    inv.push_back(wid);

                    cout << "Книгу успішно взято. Книги у вас: ";
                    for (const string& d : inv) 
                        cout << d << " ";
                    cout << endl;
                } else {
                    cout << "Такої книги не існує або її немає в наявності." << endl;
                }
            }
            else if(wid == "put" || wid == "Put"){
                for (const string& d : inv) 
                    cout << d << " ";
                cout << endl;
                
                cin >> wid;

               
                auto it = find(inv.begin(), inv.end(), wid);
                if (it != inv.end()) {
                    inv.erase(it);
                    BwB.push_back(wid);

                    cout << "Книгу успішно покладено. Книги у вас: ";
                    for (const string& d : inv) 
                        cout << d << " ";
                    cout << endl;
                } else {
                    cout << "Такої книги не існує або її немає у вас." << endl;
                }
            }
        }
        else if (wid == "yes" || wid == "Yes") {
            cout << "Ви вийшли" << endl;
        }
        else {
            cout << "Невідома дія" << endl;
        }
    }

    
    cout << "Залишилися книги в бібліотеці: ";
    for (const string& d : BwB) {
        cout << d << " ";
    }
    cout << endl;

     cout << "Книги у вас: ";
    for (const string& d : inv) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
