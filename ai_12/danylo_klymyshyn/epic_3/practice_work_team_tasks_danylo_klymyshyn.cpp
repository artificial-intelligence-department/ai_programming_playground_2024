#include <iostream>
#include <vector>

void listBooks(const std::vector<std::string> &books){
    for(int i = 0; i < books.size(); ++i)
        std::cout << books[i] << ", ";
}


bool doYouWantToContinue(){
    short choice;
    std::cout << "Do you want to continue?\n1) Yes, continue\n2) No, leave\n(1-2): ";
    while(true){
        std::cin >> choice;
        if(choice == 1)
            return true;
        else if (choice == 2)
            return false;
        else
            continue;
    }
}


void takeABook(const std::vector<std::string> &book, std::vector<bool> &b_a){
    std::string choice;
    std::cout << "Type the name of book you would like to take: ";
    while(true){
        std::cin.ignore(32676, '\n');
        std::getline(std::cin, choice);
        if(std::cin.fail()){
            std::cout << "Something is wrong, try again.";
            std::cin.clear();
            std::cin.ignore(32676, '\n');
            continue;
        }
        else
            break;
    }
    short temp = -1;
    for(int i = 0; i < book.size(); ++i){
        if (choice == book[i])
            temp = i;
    }
    if(b_a[temp] == true && temp != -1){
        b_a[temp] = false;
        std::cout << "Here is your book, don't forget to return it." << std::endl;
    }
    else
        std::cout << "We don't have this book, sorry." << std::endl;
}

void returnBook(const std::vector<std::string> &book, std::vector<bool> &b_a){
    std::string book_name;
    std::cout << "Type the name of book you want to return: ";
    while(true){
        std::cin.ignore(32676, '\n');
        std::getline(std::cin, book_name);
        if(std::cin.fail()){
            std::cout << "Something is wrong, try again.";
            std::cin.clear();
            std::cin.ignore(32676, '\n');
            continue;
        }
        else
            break;
    }
    short index = -2;
    for(int i = 0; i < book.size(); ++i){
        if(book_name == book[i]){
            index = i;
        }
        }
    if(index == -2){
        std::cout << "You did not take this book from our library." << std::endl;
        return;
    }

    if(b_a[index] == false){
        std::cout << "Thank you for returning the book." << std::endl;
        b_a[index] == true;
    }
    else{
        std::cout << "We already have that book. " << std::endl;
        return;
    }
}



int main(){

std::vector<std::string> books {"The Great Gatsby", "Ulysses", "In Search of Lost Time", "One Hundred Years of Solitude", "The Catcher in the Rye", "Lolita", "Nineteen Eighty Four", "Anna Karenina", "Wuthering Heights", "Don Quixote"};
std::vector<bool> books_availability {true, false, false, false, true, true, false, true, true, false};


bool escape = false;
while(!escape){


do{
short option;
bool choice;

while(true){
    abc:
    std::cout << "You are in a main menu now. Choose a option to do: \n1) List all books\n2) Take book\n3) Return book\n4) Close online library\n(1-4): "; 
    std::cin >> option;
    if(option == 1 || option == 2 || option == 3 || option == 4)
        break;
    else{
        std::cout << "Wrong answer, try again.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(32676, '\n');
        goto abc; 
    }
}
    if(option == 1){
        listBooks(books);
        choice = doYouWantToContinue();
        if(choice)
            continue;
        else
            return 0;
    }
    else if (option == 2){
        takeABook(books, books_availability);
        choice = doYouWantToContinue();
        if(choice)
            continue;
        else
            return 0;
    }
    else if(option == 3){
        returnBook(books, books_availability);
        choice = doYouWantToContinue();
        if(choice)
            continue;
        else
            return 0;
    }
    else if(option == 4){
        std::cout << "Thanks for your visit. ";
        escape = true;
        break;
    }
}
while(true);

}



    return 0;
}