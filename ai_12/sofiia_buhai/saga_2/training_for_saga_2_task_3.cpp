// Відео, звідки вчила теорію і брала приклади : https://youtu.be/FeNqHytI0fA?si=pFNgOqgP4rXbGtqn
// + спиталася за приклади кодів у chatGPT


#include <fstream>
#include <iostream>
#include <cstring>
#include <cstddef>
#include <sstream>

const char* INPUT_FILENAME = "Dani_Phenton.png";


struct Student {
    std::string first_name;
    std::string last_name;
    float bank_money;
};


//код від chat-GPT
struct StudentGPT { 
    char name[50]; 
    int age; 
    float grade; 
};
//



int main(){
    FILE* f = fopen("SomeFile.txt", "wb");
    if(!f){
        std::cerr << "Файл не створено";
        return 0;
    }
    Student current;
    current.first_name = "Sofiia";
    current.last_name = "Buhai";
    current.bank_money = 4102.32;
    fwrite(&current, sizeof(Student), 1, f);
    fclose(f);
    FILE* pf = fopen("SomeFile.txt", "rb");
    if(!pf){
        std::cerr << "Файл не знайдено";
        return 0;
    }
    current.first_name = "\0";
    current.last_name = "\0";
    current.bank_money = 0;
    fread(&current, sizeof(Student), 1, f);
    fclose(pf);
    std::cout << current.first_name << " " << current.last_name << " " << current.bank_money;
    FILE* nf = fopen("Dani_Phenton.png", "r");
    if(!nf){
        std::cerr << "Файл не створено";
        return 0;
    }
    int s=100;
    int paint[s];
    std::cout << "\n";
    while(fread(paint, sizeof(int), s, nf)){
        std::cout << paint << "\n";
    }
    fclose(nf);


    std::cout << "\n";


    // int paint[] = {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    // int s = *(&paint+1)-paint;
    // fwrite(paint, sizeof(int), s, nf);
    // fclose(nf);
    //std::rename("Test.txt", "Test.png");


    // std::ifstream file;
    // size_t size = 0;
    // std::cout << "\nAttempting to open " << INPUT_FILENAME << std::endl;
    // file.open( INPUT_FILENAME, std::ios::in | std::ios::binary | std::ios::ate );
    // char* data = 0;
    // file.seekg( 0, std::ios::end );
    // size = file.tellg();
    // std::cout << "File size: " << size << std::endl;
    // file.seekg( 0, std::ios::beg );
    // data = new char[ size - 8 + 1 ];
    // file.seekg( 8 ); // skip the header
    // file.read( data, size );
    // data[ size ] = '\0';
    // std::cout << "Data size: " << std::strlen( data ) << std::endl;


    // Приклад з Chat-GPT
    // Запис у файл 
    std::ofstream outFile("example.txt"); 
    if (outFile.is_open()) { 
        outFile << "Це приклад тексту.\n"; 
        outFile << "Навчання C++ із файлами.\n"; 
        outFile.close(); 
    } else { 
        std::cerr << "Не вдалося відкрити файл для запису.\n"; 
    } 
    // Читання з файлу 
    std::ifstream inFile("example.txt"); 
    std::string line; 
    if (inFile.is_open()) { 
        while (std::getline(inFile, line)) { 
            std::cout << line << '\n'; 
        } 
        inFile.close(); 
    } else { 
        std::cerr << "Не вдалося відкрити файл для читання.\n"; 
    }


    std::cout << "\n";


    //Мій код
    Student newSt;
    newSt.first_name = "Naner";
    newSt.last_name = "Vantek";
    newSt.bank_money = 12;
    std::ofstream file("Example.txt");
    if (file.is_open()) { 
        file << newSt.first_name << " "; 
        file << newSt.last_name << " "; 
        file << newSt.bank_money << "\n"; 
        file.close(); 
    } else { 
        std::cerr << "Не вдалося відкрити файл для запису.\n"; 
    }
    std::ifstream fil("Example.txt");
    if(fil.is_open()){
        while(std::getline(fil, line)){
            std::cout << line << "\n";
        }
        fil.close(); 
    } else {
        std::cerr << "Не вдалося відкрити файл для читання.\n";
    }


    std::cout << "\n";


    // Код від Chat-GPT
    // Запис у CSV 
    std::ofstream outFile_("data.csv"); 
    if (outFile_.is_open()) { 
        outFile_ << "Ім'я,Вік,Оцінка\n"; 
        outFile_ << "Анна,20,95\n"; 
        outFile_ << "Іван,21,88\n"; 
        outFile_ << "Олег,22,92\n"; 
        outFile_.close(); 
    } 
    // Читання з CSV 
    std::ifstream inFile_("data.csv"); 
    if (inFile_.is_open()) { 
        while (std::getline(inFile_, line)) { 
            std::stringstream ss(line); 
            std::string field; 
            while (std::getline(ss, field, ',')) { 
                std::cout << field << " "; 
            } 
            std::cout << '\n'; 
        } 
        inFile_.close(); 
    } else { 
        std::cerr << "Не вдалося відкрити CSV файл для читання.\n"; 
    }


    std::cout << "\n";

    //Мій код
    std::ofstream oFile("Test.csv");
    if(oFile.is_open()){
        oFile << "Продукт, кількість, вартість\n";
        oFile << "Помідори," << 30 << "," << 120 << "\n";
        oFile << "Кавуни," << 10 << "," << 200 << "\n";
        oFile << "Картопля," << 56 << "," << 33 << "\n";
        oFile << "Ківі," << 42 << "," << 10 << "\n";
        // oFile << "Продукт, кількість, вартість\n";
        // oFile << "Помідори, 30, 120\n";
        // oFile << "Кавуни, 10, 200\n";
        // oFile << "Картопля, 56, 33\n";
        // oFile << "Ківі, 42, 10\n";
        oFile.close();
    }
    std::ifstream iFile("Test.csv");
    if(iFile.is_open()){
        std::string lin;
        while(std::getline(iFile, lin)){
            std::stringstream ss1(lin);
            std::string l;
            while(std::getline(ss1, l, ',')){
                std::cout << l << " ";
            }
            std::cout << "\n";
        }
        iFile.close();
    } else { 
        std::cerr << "Не вдалося відкрити CSV файл для читання.\n"; 
    }


    std::cout << "\n";


    //код від chat-GPT
    // Запис у двійковий файл 
    StudentGPT student1 = {"Анна", 20, 95.5}; 
    std::ofstream ouFile("student.bin", std::ios::binary); 
    if (ouFile.is_open()) { 
        ouFile.write(reinterpret_cast<char*>(&student1), sizeof(StudentGPT)); 
        ouFile.close(); 
    } else { 
        std::cerr << "Не вдалося відкрити файл для запису.\n"; 
    } 
    // Читання з двійкового файлу 
    StudentGPT student2; 
    std::ifstream nFile("student.bin", std::ios::binary); 
    if (nFile.is_open()) { 
        nFile.read(reinterpret_cast<char*>(&student2), sizeof(StudentGPT)); 
        nFile.close(); 
        std::cout << "Ім'я: " << student2.name << "\nВік: " << student2.age << "\nОцінка: " << student2.grade << '\n'; 
    } else { 
        std::cerr << "Не вдалося відкрити файл для читання.\n"; 
    }


    std::cout << "\n";


    //мій код
    std::ofstream OFILE("MyStudList.bin", std::ios::binary);
    StudentGPT my_stud = {"Maria", 22, 95};
    if(OFILE.is_open()){
        OFILE.write(reinterpret_cast<char*>(&my_stud), sizeof(StudentGPT));
        my_stud = {"Momo", 20, 70};
        OFILE.write(reinterpret_cast<char*>(&my_stud), sizeof(StudentGPT));
        my_stud = {"Ane", 26, 63};
        OFILE.write(reinterpret_cast<char*>(&my_stud), sizeof(StudentGPT));
        my_stud = {"Annet", 20, 96};
        OFILE.write(reinterpret_cast<char*>(&my_stud), sizeof(StudentGPT));
    }
    OFILE.close();
    std::ifstream IFILE("MyStudList.bin", std::ios::binary);
    StudentGPT my_stud_h;
    if(IFILE.is_open()){
        while(IFILE.read(reinterpret_cast<char*>(&my_stud_h), sizeof(StudentGPT))){
            if(my_stud_h.grade > 90){
                std::cout << "Ім'я: " << my_stud_h.name << "\nВік: " << my_stud_h.age << "\nОцінка: " << my_stud_h.grade << '\n';
            }
        }
    }
    nFile.close(); 



    return 0;
}