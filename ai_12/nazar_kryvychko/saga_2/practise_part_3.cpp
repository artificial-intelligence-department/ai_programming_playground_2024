#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void writeToTxt(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& line : lines) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

std::vector<std::string> readFromTxt(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
    return lines;
}

void writeToCsv(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i < row.size() - 1) file << ",";
            }
            file << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

std::vector<std::vector<std::string>> readFromCsv(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            std::vector<std::string> row;
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }
            data.push_back(row);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
    return data;
}

int main() {
    std::string txtFilename = "D:\\nulp\\OP\\AllEpics\\saga_2\\practise\\example.txt"; 
    std::string csvFilename = "D:\\nulp\\OP\\AllEpics\\saga_2\\practise\\example.csv";

    std::vector<std::string> txtLines = {"Line 1", "Line 2", "Line 3"};
    writeToTxt(txtFilename, txtLines);
    std::vector<std::string> readTxtLines = readFromTxt(txtFilename);
    std::cout << "Contents of " << txtFilename << ":" << std::endl;
    for (const auto& line : readTxtLines) {
        std::cout << line << std::endl;
    }

    std::vector<std::vector<std::string>> csvData = {
        {"Name", "Age", "City"},
        {"Alice", "25", "New York"},
        {"Bob", "30", "Los Angeles"}
    };
    writeToCsv(csvFilename, csvData);
    std::vector<std::vector<std::string>> readCsvData = readFromCsv(csvFilename);
    std::cout << "Contents of " << csvFilename << ":" << std::endl;
    for (const auto& row : readCsvData) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
