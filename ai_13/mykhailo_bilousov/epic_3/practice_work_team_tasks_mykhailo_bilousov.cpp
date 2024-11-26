#include <iostream>
#include <vector>
#include <format>

#define MIN(a,b) ((a)<(b)?(a):(b))

void list_books(std::vector<std::string> book_names, std::vector<bool> book_available);
void list_available(std::vector<std::string> book_names, std::vector<bool> book_available);
void list_borrowed(std::vector<std::string> book_names, std::vector<bool> book_available);
void borrow_book(std::vector<std::string> book_names, std::vector<bool>& book_available, size_t index);
void borrow_book(std::vector<std::string> book_names, std::vector<bool>& book_available);
void return_book(std::vector<std::string> book_names, std::vector<bool>& book_available, size_t index);
void return_book(std::vector<std::string> book_names, std::vector<bool>& book_available);

int main()
{
    std::vector<std::string> book_names = {
        "The C Programming Language", 
        "The C++ Programming Language", 
        "1984", 
        "Introduction to Algorithms",
        "Cybersecurity For Dummies"
    };
    std::vector<bool> book_available;
    for(auto i = book_names.begin(); i != book_names.end(); i++) 
    {
        book_available.push_back(true);
    }
    std::string input;
    int choice = 5;
main_menu:
    do
    {
        std::cout 
            << "1. List books" << std::endl
            << "2. Borrow book" << std::endl
            << "3. Return book" << std::endl
            << "0. Quit" << std::endl
            << "Select your action: ";
        std::cin >> input;
        try 
        {
            choice = std::stoi(input);
        }
        catch (const std::out_of_range& e)
        {
            choice = -1; // invalid input so just set it to -1
        }
        catch (const std::invalid_argument& e)
        {
            choice = -1; // invalid input so just set it to -1
        }
        switch (choice)
        {
            case 0:
                std::cout << "Quitting!" << std::endl;
                break;

            case 1:
                list_books(book_names, book_available);
                break;
            
            case 2:
                borrow_book(book_names, book_available);
                break;
            
            case 3:
                return_book(book_names, book_available);
                break;
            
            default:
                std::cout << "Invalid option! Valid inputs are: 0, 1, 2, 3" << std::endl;
                goto main_menu;
        }
    } 
    while (choice != 0);
}

void list_books(std::vector<std::string> book_names, std::vector<bool> book_available)
{
    size_t size = MIN(book_names.size(), book_available.size());
    for(size_t i = 0; i < size; i++) 
    {
        std::cout << "ID: " << i << " Book name: \"" << book_names[i] << "\" available: " << (book_available[i] ? "yes" : "no") << std::endl;
    }
}

void list_available(std::vector<std::string> book_names, std::vector<bool> book_available)
{
    size_t size = MIN(book_names.size(), book_available.size());
    std::cout << "Available books:" << std::endl;
    for(size_t i = 0; i < size; i++) 
    {
        if (book_available[i]) std::cout << "ID: " << i << " Book name: \"" << book_names[i] << "\"" << std::endl;
    }
}

void list_borrowed(std::vector<std::string> book_names, std::vector<bool> book_available)
{
    size_t size = MIN(book_names.size(), book_available.size());
    std::cout << "Borrowed books:" << std::endl;
    for(size_t i = 0; i < size; i++) 
    {
        if (!book_available[i]) std::cout << "ID: " << i << " Book name: \"" << book_names[i] << "\"" << std::endl;
    }
}

void borrow_book(std::vector<std::string> book_names, std::vector<bool>& book_available, size_t index)
{
    if (index >= book_available.size())
    {
        std::cout << "Index " << index << " is invalid! Try a smaller number like 0 or " << book_available.size() - 1 << std::endl;
        return;
    }
    if (book_available[index] == false)
    {
        std::cout << "Book " << index << " is not available!" << std::endl;
        return;
    }
    book_available[index] = false;
    std::cout << "Book " << index << " has been borrowed" << std::endl;
}

void borrow_book(std::vector<std::string> book_names, std::vector<bool>& book_available)
{
    std::string input;
    size_t index;
    list_available(book_names, book_available);
    std::cout << "Enter choice: ";
    std::cin >> input;
    try
    {
        index = (size_t)std::stoull(input);
    }
    catch (const std::exception& e)
    {
        std::cout << "ERROR! " << typeid(e).name() << std::endl;
        return;
    }
    borrow_book(book_names, book_available, index);
}

void return_book(std::vector<std::string> book_names, std::vector<bool>& book_available, size_t index)
{
    if (index >= book_available.size())
    {
        std::cout << "Index " << index << " is invalid! Try a smaller number like 0 or " << book_available.size() - 1 << std::endl;
        return;
    }
    if (book_available[index] == true)
    {
        std::cout << "Book " << index << " is already returned!" << std::endl;
        return;
    }
    book_available[index] = true;
    std::cout << "Book " << index << " has been returned" << std::endl;
}

void return_book(std::vector<std::string> book_names, std::vector<bool>& book_available)
{
    std::string input;
    size_t index;
    list_borrowed(book_names, book_available);
    std::cout << "Enter choice: ";
    std::cin >> input;
    try
    {
        index = (size_t)std::stoull(input);
    }
    catch (const std::exception& e)
    {
        std::cout << "ERROR! " << typeid(e).name() << std::endl;
        return;
    }
    return_book(book_names, book_available, index);
}