// #include <iostream>
// #include <fstream>
// #include <string>

// int main() {
//     // Запис у файл
//     std::ofstream outFile("example.txt");
//     outFile << "Привіт, світ!" << std::endl;
//     outFile << "Запис даних у текстовий файл." << std::endl;
//     outFile.close();

//     // Читання з файлу
//     std::ifstream inFile("example.txt");
//     std::string line;
//     while (std::getline(inFile, line)) {
//         std::cout << line << std::endl;
//     }
//     inFile.close();

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <sstream>

// int main() {
//     // Запис у файл
//     std::ofstream outFile("example.txt");
//     outFile << "Ім'я,Вік,Місто" << std::endl;
//     outFile << "Анна,23,Київ" << std::endl;
//     outFile << "Олексій,30,Львів" << std::endl;
//     outFile.close();

//     // Читання з файлу
//     std::ifstream inFile("example.txt");
//     std::string line;
//     while (std::getline(inFile, line)) {
//         std::stringstream ss(line);
//         std::string item;
//         while (std::getline(ss, item, ',')) {
//             std::cout << item << " ";
//         }
//         std::cout << std::endl;
//     }
//     inFile.close();

//     return 0;
// }


#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
};

int main() {
    // Запис у файл
    std::ofstream outFile("example.bin", std::ios::binary);
    Data d1 = {1, "Анна"};
    Data d2 = {2, "Олексій"};
    outFile.write(reinterpret_cast<char*>(&d1), sizeof(Data));
    outFile.write(reinterpret_cast<char*>(&d2), sizeof(Data));
    outFile.close();

    // Читання з файлу
    std::ifstream inFile("example.bin", std::ios::binary);
    Data d;
    while (inFile.read(reinterpret_cast<char*>(&d), sizeof(Data))) {
        std::cout << "ID: " << d.id << ", Name: " << d.name << std::endl;
    }
    inFile.close();

    return 0;
}