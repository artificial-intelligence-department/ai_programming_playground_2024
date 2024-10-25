#include <iostream>
#include <vector>

enum Status{
    availabel,
    unavailabel
};

std::vector<std::string> books;
std::vector<Status> booksStatus;

void addBook(std::string book, Status status= availabel){
    books.push_back(book);
    booksStatus.push_back(status);
}

void showBooks(){
    for(std::string title : books) std::cout << title << std::endl;
}


bool isAvailabel(std::string title){ 
    int i = 0;
    for(std::string& book : books) {
        if(title == book) break;
        i++;
    }
    int counter = 0;
    for(Status& status : booksStatus){
        if(i == counter) {
            if(status == availabel){
                std::cout <<  "Book is availabel. You have take it\n";
                status = unavailabel;
                return true;
            }
            else{
                std::cout << ("Book isn't availabel. You cant take it\n");
                return false;
            }
        }
        counter++;
    }
    return false;
}

int main(){
    addBook("Atlas_shrugged");
    addBook("Plague");
    addBook("Don_Quixote", unavailabel);
    addBook("Idk1");
    addBook("Idk2", unavailabel);
    addBook("idk3", unavailabel);
    std::cout << "Enter [0] - to exit\n";
    bool stat;
    int query;
    std::string title;
    while(true){
        input : std::cout << "[1] - to display books list\n[2] - take a book\n";
        std::cin >> query;
        if(query != 1 && query != 2 && query != 0) {
            std::cout << "Wrong input!\n";
            goto input;
        }
        switch (query)
        {
        case 1:
            showBooks();
            break;
        case 2:
            do{
                std::cout << "Enter book title: ";
                std::cin >> title;
            }while (!isAvailabel(title) && title != "0");
            if(title == "0") return 0;
            break;
        case 0: return 0;
        }
    }
}