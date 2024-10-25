#include <iostream>
#include <vector>
#include <string>
#include <limits>


extern std::vector<std::string> bookList;
extern std::vector<std::string> bookListAvailable;
int indexFind(std::vector<std::string> bookList, std::string target);
void takingBooks (std::vector<std::string>& bookList, std::vector<std::string>& bookListAvailable);
void listingBooks(std::vector<std::string> bookList);
void returningBooks(std::vector<std::string>& bookList);


int main()
{
    std::cout << "Congratulations! You're in online library." << std::endl;
    std::string userOption;
    do
    {
        point:
        std::cout << "Availiable options:" << std::endl <<
        "1 - List all books" << std::endl <<
        "2 - Take a book (if availiable)" << std::endl <<
        "3 - Return a book" << std::endl <<
        "Enter a Number of the option: " << std::endl;
        std::cin >> userOption;

        if (userOption == "1")
            listingBooks(bookList);

        else if (userOption == "2")
            takingBooks(bookList, bookListAvailable);

        else if (userOption == "3")
            returningBooks(bookList);
        else
        {
            std::cout << "You have eneter not a correct option. You'll be moved to the main menu." << std::endl;
            goto point;
        }

        std::cout << "Choose option:" << std::endl <<
        "1. Return to the main menu." << std::endl <<
        "2. End session" << std::endl;
        std::cin >> userOption;
        if (userOption == "2")
            break;
    }
    while(true);

    return 0;
}



std::vector<std::string> bookList = {
        "Dune", 
        "Neuromancer", 
        "Snow Crash", 
        "The Hitchhiker's Guide to the Galaxy", 
        "Brave New World", 
        "The War of the Worlds", 
        "Fahrenheit 451", 
        "The Left Hand of Darkness", 
        "The Expanse: Leviathan Wakes", 
        "The Three-Body Problem", 
        "Do Androids Dream of Electric Sheep?", 
        "Altered Carbon", 
        "The Man in the High Castle", 
        "The Time Machine", 
        "Ringworld", 
        "The Moon is a Harsh Mistress", 
        "The Forever War"
    };
std::vector<std::string> bookListAvailable (bookList.size(), "Available");

void listingBooks(std::vector<std::string> bookList)
{
    std::cout << "All the books in our library:" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < bookList.size(); i ++)
        std::cout << "- " << bookList[i] << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;

    return;
}

void takingBooks (std::vector<std::string>& bookList, std::vector<std::string>& bookListAvailable)
{
    int index;
    std::cout << "All books status: " << std::endl;
    for (std::string book: bookList)
    {
        index = indexFind(bookList, book);
        std::cout << index << ". " << book << std::endl << "Status: "<< bookListAvailable[index] << std::endl;        
    }
    do
    {
        std::cout << "What book would you like to take. Enter the number of it: ";
        std::cin >> index;
        if(index >= bookList.size() || index < 0)
            std::cout << "You have enetred not a correct number. Please try again" << std::endl;
        else if(bookListAvailable[index] == "Unavailable")
            std::cout << "This book is unavailable. Please choose another option." << std::endl;
    }
    while(index >= bookList.size() || index < 0 || bookListAvailable[index] == "Unavailable");
    bookListAvailable[index] = "Unavailable";
    std::cout << "You have taken a book. Good reading!" << std::endl;
    return;

}

int indexFind(std::vector<std::string> bookList, std::string target) 
{
    for (size_t i = 0; i < bookList.size(); i++) 
        if (bookList[i] == target) 
            return i;
    return -1; 
}

void returningBooks(std::vector<std::string>& bookList)
{
    for (int i = 0; i < bookList.size(); i++)
        std::cout << i << ". " << bookList[i] << std::endl;        
    std::cout << "What book would you like to return? Enter the index" << std::endl;
    int index;
    std::cin >> index;
    if(index >= bookList.size() || index < 0)
        std::cout << "That's not a book from our library" << std::endl;
    else
        {
            bookListAvailable[index] = "Available"; 
            std::cout << "You have successfuly returned a book" << std::endl; 
        }
    return;
}