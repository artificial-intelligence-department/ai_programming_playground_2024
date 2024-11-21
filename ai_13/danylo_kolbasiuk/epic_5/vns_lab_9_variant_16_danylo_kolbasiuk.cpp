#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>


bool check_line_conditions(const std::string &line) {
    if (line.empty()) return false;
    char first = line[0];
    char last = line[line.size() - 1];
    return (first == 'A' && last == 'Z');
}


int count_words_in_line(const std::string &line) {
    std::stringstream stream(line);
    std::string word;
    int count = 0;
    while (stream >> word) {
        count++;
    }
    return count;
}

int main() {
    std::string filename1 = "F1.txt";
    std::string filename2 = "F2.txt";

    std::ofstream file_F1(filename1);
    if (!file_F1) {
        std::cerr << "Failed to create the file F1!" << std::endl;
        return 1;
    }

    
    file_F1 << "ABCDEFG Z\n";
    file_F1 << "ssdfgsdanfd\n";
    file_F1 << "Adasa Z\n";
    file_F1 << "sdfsdf\n";
    file_F1 << "AAAZZZ Z\n";
    file_F1 << "dffsfdsfd\n";
    file_F1 << "werwreowo\n";
    file_F1 << "Aaaaazzzz Z\n";
    file_F1 << "weffsdsfd\n";
    file_F1 << "ertweertsdfg\n";
    file_F1.close();

    std::ifstream file_F1_in(filename1);
    if (!file_F1_in) {
        std::cerr << "Failed to open F1 for reading!" << std::endl;
        return 1;
    }

    std::ofstream file_F2(filename2, std::ios::trunc);
    if (!file_F2) {
        std::cerr << "Failed to create F2!" << std::endl;
        return 1;
    }

    int N1 = 4; 
    int N2 = 9; 

    std::string line;
    int line_number = 0;
    while (std::getline(file_F1_in, line)) {
        line_number++;
        if (line_number >= N1 && line_number <= N2 && check_line_conditions(line)) {
            file_F2 << line << "\n";
        }
    }

    file_F1_in.close();
    file_F2.close();

    std::ifstream file_F2_in(filename2);
    if (!file_F2_in) {
        std::cerr << "Failed to open F2 for reading!" << std::endl;
        return 1;
    }

    if (std::getline(file_F2_in, line)) {
        int word_count = count_words_in_line(line);
        std::cout << "Counted words in F2: " << word_count << std::endl;
    } else {
        std::cout << "F2 is empty" << std::endl;
    }

    file_F2_in.close();
    return 0;
}
