#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> name = {"To Kill a Mockingbird", "1984", "Pride and Prejudice", "The Great Gatsby",
                                     "Moby Dick"};
    std::vector<bool> status = {1, 1, 1, 1, 1};
    bool work = 1;
    while (work)
    {
    restart:
        int ind = -1;
        int choice = -1;
        int choice2 = -1;
        std::cout << "(1)Show all books\n(2)Show books' availability\n(3)Take a book(if available)\n(4)return the "
                     "book\n(5)exit\n";
        std::cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            std::cout << "please enter valid number\n";
            goto restart;
        }
        std::cout << '\n';
        switch (choice)
        {
        case 1:
            for (auto book : name)
            {
                std::cout << book << '\n';
            }
            break;
        case 2:
            for (int i = 0; i < name.size(); i++)
            {
                std::cout << name[i];
                if (status[i] == 0)
                {
                    std::cout << " - unavailable";
                }
                std::cout << '\n';
            }
            break;
        case 3:
            ind = -1;
            std::cout << "enter book index(starting from 1): ";
            std::cin >> ind;
            if (status[ind - 1] == 1)
            {
                std::cout << "enjoy the book\n";
                status[ind - 1] = 0;
            }
            else
            {
                std::cout << "sorry this book is unavailable\n";
            }
            break;
        case 4:
            ind = -1;
            std::cout << "enter index of book you want to return: ";
            std::cin >> ind;
            if (status[ind - 1] == 0)
            {
                std::cout << "thanks for returning\n";
                status[ind - 1] = 1;
            }
            else
            {
                std::cout << "it is already present\n";
            }
            break;
        case 5:
            exit(0);
        }
        do
        {
            std::cout << "\nwant to continue?(1|0) ";
            std::cin >> choice2;
        } while (choice2 != 1 && choice2 != 0);
        if (choice2 == 0)
        {
            exit(0);
        }
        std::cout << '\n';
    }
}
