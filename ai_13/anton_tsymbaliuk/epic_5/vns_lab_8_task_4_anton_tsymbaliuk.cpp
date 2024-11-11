#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Human{
    std::string fullName;
    std::string address;
    std::string phoneNumber;
    int age;
};


void addItem(const std::string& fileName, Human& human){
    std::ofstream file(fileName, std::ofstream::binary | std::ofstream::app);
    size_t size = human.fullName.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(&human.fullName[0], size);
    size = human.address.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(&human.address[0], size);
    size = human.phoneNumber.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(&human.phoneNumber[0], size);

    file.write(reinterpret_cast<char*>(&human.age), sizeof(human.age));
    file.close();
}

void read(const std::string& fileName){
    std::ifstream file(fileName, std::ifstream::binary);
    Human human;
    while(true){
        size_t size;
        if(!file.read(reinterpret_cast<char*>(&size), sizeof(size))) break;

        human.fullName.resize(size);
        file.read((&human.fullName[0]), size);

        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.address.resize(size);
        file.read((&human.address[0]), size);
        
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.phoneNumber.resize(size);
        file.read((&human.phoneNumber[0]), size);
        

        file.read(reinterpret_cast<char*>(&human.age), sizeof(human.age));
        std::cout << "\nFull name: " << human.fullName << "\nAddress: " << human.address << "\nPhone number: " << human.phoneNumber << "\nAge: " << human.age << std::endl;
    }
    file.close();
}

void deleteWithAgeOf(const std::string& fileName, int age){
    std::ifstream file(fileName, std::ios::binary);
    Human human;
    std::ofstream newFile("temp.bat", std::ios::binary );
    while(true){
        size_t size;
        if(!file.read(reinterpret_cast<char*>(&size), sizeof(size))) break;
        human.fullName.resize(size);
        file.read((&human.fullName[0]), size);

        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.address.resize(size);
        file.read((&human.address[0]), size);
        
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.phoneNumber.resize(size);
        file.read((&human.phoneNumber[0]), size);
        

        file.read(reinterpret_cast<char*>(&human.age), sizeof(human.age));
        if(human.age != age) {
            size_t size = human.fullName.size();
            newFile.write(reinterpret_cast<char*>(&size), sizeof(size));
            newFile.write(&human.fullName[0], size);

            size = human.address.size();
            newFile.write(reinterpret_cast<char*>(&size), sizeof(size));
            newFile.write(&human.address[0], size);

            size = human.phoneNumber.size();
            newFile.write(reinterpret_cast<char*>(&size), sizeof(size));
            newFile.write(&human.phoneNumber[0], size);

            newFile.write(reinterpret_cast<char*>(&human.age), sizeof(human.age));
        }
    }
    file.close();
    newFile.close();
    std::remove(fileName.c_str());
    std::rename("temp.bat", fileName.c_str());
}

void addAfterPhoneNumber(const std::string& fileName, const std::string& phoneNumber, Human& h){
    std::fstream fileIn(fileName, std::fstream::binary | std::fstream::in);
    Human human;
    std::vector<Human> vec;
    size_t size;
    while (true)
    {
        if(!fileIn.read(reinterpret_cast<char*>(&size), sizeof(size))) break;
        human.fullName.resize(size);
        fileIn.read((&human.fullName[0]), size);

        fileIn.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.address.resize(size);
        fileIn.read((&human.address[0]), size);
        
        fileIn.read(reinterpret_cast<char*>(&size), sizeof(size));
        human.phoneNumber.resize(size);
        fileIn.read((&human.phoneNumber[0]), size);

        fileIn.read(reinterpret_cast<char*>(&human.age), sizeof(human.age));
        vec.push_back(human);
    }
    
    fileIn.close();
    std::fstream file(fileName, std::fstream::binary | std::fstream::out);

    for(Human& hu : vec){
        size = hu.fullName.size();
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(&hu.fullName[0], size);
        size = hu.address.size();
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(&hu.address[0], size);
        size = hu.phoneNumber.size();
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(&hu.phoneNumber[0], size);

        file.write(reinterpret_cast<char*>(&hu.age), sizeof(hu.age));
        if(hu.phoneNumber == phoneNumber){
            size = h.fullName.size();
            file.write(reinterpret_cast<char*>(&size), sizeof(size));
            file.write(&h.fullName[0], size);
            size = h.address.size();
            file.write(reinterpret_cast<char*>(&size), sizeof(size));
            file.write(&h.address[0], size);
            size = h.phoneNumber.size();
            file.write(reinterpret_cast<char*>(&size), sizeof(size));
            file.write(&h.phoneNumber[0], size);

            file.write(reinterpret_cast<char*>(&h.age), sizeof(h.age));
        }
    }
}




int main(){ 
    std::string fileName = "human.bat";
    Human human;
    int q = -1;
    int age;
    std::string phoneNumber;
    std::string fullName;
    std::string Address;
    while(q != 0){
        std::cout << "[1] - to add human\n[2] - delete with certain age\n[3] - add after certain phone number\n[4] - show file\n[0] - exit\n";
        std::cin >> q;
        std::cin.ignore();
        switch (q) {
            case 1:
                std::cout << "Full name: ";
                std::getline(std::cin, human.fullName);
                std::cout << "Address: ";
                std::getline(std::cin, human.address);
                std::cout << "Phone number: ";
                std::getline(std::cin, human.phoneNumber);
                std::cout << "Age: ";
                std::cin >> human.age;
                std::cin.ignore();
                addItem(fileName, human);
                break;
            case 2:
                std::cout << "Age to delete: ";
                std::cin >> age;
                deleteWithAgeOf(fileName, age);
                break;
            case 3:
                std::cout << "Enter phone number after which to add a human: ";
                std::cin >> phoneNumber;
                std::cin.ignore();
                std::cout << "Full name: ";
                std::getline(std::cin, human.fullName);
                std::cout << "Address: ";
                std::getline(std::cin, human.address);
                std::cout << "Phone number: ";
                std::getline(std::cin, human.phoneNumber);
                std::cout << "Age: ";
                std::cin >> human.age;
                std::cin.ignore();
                addAfterPhoneNumber(fileName, phoneNumber, human);
                break;
            case 4:
                read(fileName);
                break;
        }
    }
    return 0;
}