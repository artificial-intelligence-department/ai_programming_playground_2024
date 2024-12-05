#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum FileOperationStatus {
    OperationSuccess,
    OperationFailure,
    FileOpenError,
    FileWriteError,
    FileCloseError
};

FileOperationStatus writeFile(const char *fileName, const char *data) {
    fstream file(fileName, ios::out);
    if (!file.is_open()) {
        return FileOperationStatus::FileOpenError;
    }

    file << data;
    if (file.fail()) {
        return FileOperationStatus::FileWriteError;
    }

    file.close();
    if (file.bad()) {
        return FileOperationStatus::FileCloseError;
    }

    return FileOperationStatus::OperationSuccess;
}

FileOperationStatus copyFileContents(const char *sourceFile, const char *destinationFile) {
    fstream source(sourceFile, ios::in);
    fstream destination(destinationFile, ios::out);
    
    if (!source.is_open() || !destination.is_open()) {
        return FileOperationStatus::FileOpenError;
    }

    destination << source.rdbuf();
    if (source.fail() || destination.fail()) {
        return FileOperationStatus::FileWriteError;
    }

    source.close();
    destination.close();
    if (source.bad() || destination.bad()) {
        return FileOperationStatus::FileCloseError;
    }

    return FileOperationStatus::OperationSuccess;
}

string getFileOperationResultMessage(FileOperationStatus statusCode) {
    switch (statusCode) {
        case OperationSuccess:
            return "Operation completed successfully.";
        case OperationFailure:
            return "General failure.";
        case FileOpenError:
            return "Error opening file.";
        case FileWriteError:
            return "Error writing to file.";
        case FileCloseError:
            return "Error closing file.";
        default:
            return "Unknown error.";
    }
}

int main() {
    string fileName = "OutputFile.txt", fileContent;
    cout << "Enter content to save in the file: ";
    getline(cin, fileContent);
    
    FileOperationStatus writeStatus = writeFile(fileName.c_str(), fileContent.c_str());
    cout << "\nFile write operation status: " << getFileOperationResultMessage(writeStatus) << endl;

    string sourceFile = "OutputFile.txt", targetFile;
    cout << "\nEnter the name of the file to copy to: ";
    getline(cin, targetFile);

    FileOperationStatus copyStatus = copyFileContents(sourceFile.c_str(), targetFile.c_str());
    cout << "\nFile copy operation status: " << getFileOperationResultMessage(copyStatus) << endl;

    return 0;
}
