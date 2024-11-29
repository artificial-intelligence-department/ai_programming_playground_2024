#include <iostream>
#include <fstream>
#include <cstring>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    std::ofstream file(name); 
    
    if (!file.is_open()) {
        return Failure;  
    }
    file << content;  
    
    if (!file) {
        return Failure;  
    }
    
    file.close();  
    
    return Success; 
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
    std::ifstream source(file_from, std::ios::binary);  
    if (!source.is_open()) {
        return Failure;  
    }
    
    std::ofstream destination(file_to, std::ios::binary);  
    if (!destination.is_open()) {
        return Failure;  
    }
    
    destination << source.rdbuf(); 
    
    if (!destination) {
        return Failure;  
    }
    
    source.close();  
    destination.close();  
    
    return Success;  
}

int main() {
    char *filename = "example.txt";
    
    char content[100]; 
    std::cout << "Введіть вміст файлу: ";
    fgets(content, sizeof(content), stdin);  
    
    FileOpResult writeResult = write_to_file(filename, content);
    if (writeResult == Success) {
        std::cout << "файл успішно створено і записано" << std::endl;
    } else {
        std::cout << "помилка при створенні або записі файлу" << std::endl;
    }
    
    const char *source_file = "example.txt";
    const char *destination_file = "copied.txt";
    
    FileOpResult copyResult = copy_file(source_file, destination_file);
    if (copyResult == Success) {
        std::cout << "файл успішно скопійовано" << std::endl;
    } else {
        std::cout << "помилка при копіюванні файлу" << std::endl;
    }
    
    return 0;
}
