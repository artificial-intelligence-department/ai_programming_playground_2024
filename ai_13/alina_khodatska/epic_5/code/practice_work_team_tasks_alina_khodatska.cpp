#include <iostream>
#include <fstream>
#include <string>

// ���������� ����������� ��� ���������� ��������
enum FileOpResult { Success, Failure };

// ������� ��� ������ � ����
FileOpResult write_to_file(const char* name, const char* content) {
    // �������� ������� ���������
    if (name == nullptr || content == nullptr) {
        return Failure;
    }

    // ������ ������� ���� ��� ������
    std::ofstream outfile(name);
    if (!outfile.is_open()) {
        return Failure;
    }

    // ����� ����� � ����
    outfile << content;

    // �������� �� ����� ��� �������
    if (outfile.fail()) {
        return Failure;
    }

    // �������� �����
    outfile.close();

    // �������� �� ���� ��� ������ ��������
    if (outfile.fail()) {
        return Failure;
    }

    return Success;
}

// ������� ��� ��������� ����� � ������ ����� � �����
FileOpResult copy_file(const char* file_from, const char* file_to) { 
    // file_from - ���������� ����, file_to - ����, � ���� �������, const char* - �������� �� ����������� ����� �������
    // �������� ������� ���������
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    // ������ ������� ���� ��� �������
    std::ifstream infile(file_from, std::ios::binary);
    if (!infile.is_open()) {
        return Failure;
    }

    // ������ ������� ���� ��� ������
    std::ofstream outfile(file_to, std::ios::binary);
    if (!outfile.is_open()) {
        infile.close();
        return Failure;
    }

    // ��������� �����
	outfile << infile.rdbuf(); // rdbuf() - ������� �������� �� ��'���, ���� ������ ���� �����

    // �������� �� ����� ��� �������
    if (outfile.fail() || infile.fail()) {
        infile.close();
        outfile.close();
        return Failure;
    }

    // �������� �����
    infile.close();
    outfile.close();

    // �������� �� ����� ���� ������ ������
    if (infile.fail() || outfile.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    // ����� � ����
    std::string filename;
    std::string content;

    std::cout << "Enter filename for write operation: ";
    std::getline(std::cin, filename);

    std::cout << "Enter content to write to the file: ";
    std::getline(std::cin, content);

	FileOpResult result = write_to_file(filename.c_str(), content.c_str()); 
	//filename.c_str() - ������� �������� �� ����� �������, ���� ������ ��'� �����
    //content.c_str() - ������� �������� �� ����� �������, ���� ������ ���� �����
    if (result == Success) {
        std::cout << "File written successfully." << std::endl;
    }
    else {
        std::cout << "Failed to write to file." << std::endl;
    }

    // ��������� �����
    std::string sourceFile;
    std::string destinationFile;

    std::cout << "\nEnter source filename for copy operation: ";
    std::getline(std::cin, sourceFile);

    std::cout << "Enter destination filename for copy operation: ";
    std::getline(std::cin, destinationFile);

    result = copy_file(sourceFile.c_str(), destinationFile.c_str()); 
	// sourceFile.c_str() - ������� �������� �� ����� �������, ���� ������ ��'� ��������� ����� 
    // destinationFile.c_str() - ������� �������� �� ����� �������, ���� ������ ��'� �����, � ���� �������
    if (result == Success) {
        std::cout << "File copied successfully." << std::endl;
    }
    else {
        std::cout << "Failed to copy file." << std::endl;
    }

    return 0;
}
