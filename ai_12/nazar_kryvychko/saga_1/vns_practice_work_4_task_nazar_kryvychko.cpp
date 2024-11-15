#include <iostream> 
#include <vector> 
#include <fstream> 
#include <cstdlib> 
#include <ctime> 

 

// Структура для зберігання векторів і їх середнього значення 
struct SequenceData { 
    std::vector<int> values; 
    double average; 
    SequenceData(size_t size) : values(size), average(0.0) {} 
}; 

 

void fill_random(std::vector<int>& v) { 
    for (size_t i = 0; i < v.size(); i++) { 

        v[i] = rand() % 10 + 1; 
    } 
} 

 

double calculate_average(const std::vector<int>& v) { 
    int sum = 0; 
    for (size_t i = 0; i < v.size(); i++) { 
        sum += v[i]; 
    } 
    return static_cast<double>(sum) / v.size(); 
} 

 

// Функція для запису даних у файл 
void write_to_file(const char* filename, SequenceData* data) { 
    std::ofstream outFile(filename); 
    if (outFile.is_open()) { 
        for (int value : data->values) { 
            outFile << value << ' '; 
        } 
        outFile << "\nAverage of sequence: " << data->average << std::endl; 
        outFile.close(); 
        std::cout << "Data written to file: " << filename << std::endl; 
    } else { 
        std::cerr << "Error opening file for writing.\n"; 
    } 
} 

 

// Функція для зчитування даних з файлу 
void read_from_file(const char* filename) { 
    std::ifstream inFile(filename); 
    if (inFile.is_open()) { 
        std::cout << "Reading from file: " << filename << std::endl; 
        std::string line; 
        while (std::getline(inFile, line)) { 
            std::cout << line << std::endl; 
        } 
        inFile.close(); 
    } else { 
        std::cerr << "Error opening file for reading.\n"; 
    } 
} 

 

int main() { 

    srand(static_cast<unsigned int>(time(0))); 
    SequenceData seq1(10), seq2(10), seq3(10); 

     
    fill_random(seq1.values); 
    fill_random(seq2.values); 
    fill_random(seq3.values); 

 

    seq1.average = calculate_average(seq1.values); 
    seq2.average = calculate_average(seq2.values); 
    seq3.average = calculate_average(seq3.values); 

    const char* filename = "sequences.txt"; 

    write_to_file(filename, &seq1); 
    write_to_file(filename, &seq2); 
    write_to_file(filename, &seq3); 

    std::cout << "Значення векторів записано у файл.\n\n"; 

    // Зчитуємо дані з файлу 
    read_from_file(filename); 

    return 0; 

} 

 