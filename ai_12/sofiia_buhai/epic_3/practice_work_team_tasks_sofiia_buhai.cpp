#include <iostream>
#include <vector>

// функція для розрахунку кількости книг у бібліотеці та їх виводу
int number_of_books(std::vector<int> book_availible, std::vector<std::string> book_name){
    int number=0;

    for(int i : book_availible){
        if(i==1){
            number+=1;
        }  
    }
    std::cout << "\nЗараз у бібліотеці " << number << " книг(и)\n";
    for (int i = 0; i < book_availible.size(); i++)
    {
        if(book_availible[i]==1){
            std::cout << book_name[i] << "\n";
        }
    }
     return number;
}

//функція для взяття книги
int get_a_book(std::vector<int> &book_availible, std::vector<std::string> book_name, int size){
    int is_book;
    std::string book;
    std:: cout << "\nЯку книгу ви хотіли б узяти? : ";   
    std::cin.ignore();
    std::getline(std::cin, book);                              //введення назви книги
    for(int i=0; i < size; i++){
        if(book_name[i].compare(book) == 0){                   //перевірка, чи та назва
            if(book_availible[i]==1){                          //перевірка, чи книга є
                std::cout << "\nКнига у наявності. Гарного читання";
                book_availible[i]=0;
                is_book=1;
                break;
            } else {
                is_book = 0;
            }
        }                
    }
    if(is_book == 0){
        std::cout << "\nКниги немає у наявності";
    }
    return is_book;
}

// функціїя для повернення книги
int return_a_book(std::vector<int> &book_availible, std::vector<std::string> book_name, int size){
    int is_book;
    std::string book;
    std:: cout << "\nЯку книгу ви хотіли би повернути? : ";   
    std::cin.ignore();
    std::getline(std::cin, book);                              //введення назви книги
    for(int i=0; i < size; i++){
        if(book_name[i].compare(book) == 0){                   //перевірка, чи та назва
            if(book_availible[i]==0){                          //перевірка, чи книги немає
                std::cout << "\nДякую за повернення. Приходьте ще!";
                book_availible[i]=1;
                is_book=0;
                break;
            } else {
                is_book = 1;
            }
        }           
    }
    if(is_book == 1){
        std::cout << "\nКнига вже у наявності";
    }
    return is_book;
}


int main() {
    std::vector<std::string> book_name = {
        "Alphabet", 
        "Angels of evil", 
        "Mermaid from 9-B",
        "Ukraine",
        "How to kill with style",
        "Poetry",
        "W.I.T.C.H",
        "You",
        "Evangelion",
        "Blue period",
        "Psycology from Naruto",
        "Death Note"};
    std::vector<int> book_availible;
    int answer = 0, size = book_name.size();

    for(int i=0; i<size; i++){
        book_availible.push_back(1);
    }

    do{
        Question:
        std::cout << "\nЩо ви хочете зробити? Будь ласка, оберіть номер дії: \n1) Порахувати книги" <<
        " \n2) Взяти книгу \n3) Повернути книгу\n";
        std::cin >> answer;

        switch(answer){
            case 1:
                number_of_books(book_availible, book_name);
                break;
            case 2:
                get_a_book(book_availible, book_name, size);
                break;
            case 3:
                return_a_book(book_availible, book_name, size);
                break;
            default :
                std::cerr << "Упс, неправильно ввели! Спробуйте ще раз\n";
        }
        std::cout <<"\nХочете подовжити? \n4) Продовжити \n5) Вийти \n";
        std::cin >> answer;
        while(answer!=5){
            goto Question;
        }
    } while(answer!=5);
    return 0;
}