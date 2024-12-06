  #include <iostream>
  #include <fstream>
  #include <string>
  using namespace std;

  enum FileOrResult {Success,Failure};

  FileOrResult write_to_file (const char* name, const char* content){
    if(name == nullptr || content == nullptr){
      return Failure;
    }

    ofstream outFile(name,ios::out);
    if(!outFile){
      return Failure;
    }

    outFile << content;
    if(!outFile.good()){
      return Failure;
    }

    outFile.close();
    if(!outFile.good()){
      return Failure;
    }

    outFile.close();
    return Success;
  }

  FileOrResult copy_file (const char* file_from, const char* file_to){
    if(file_from == nullptr || file_to == nullptr){
      cerr << "Error: Invalid parameters for copy_file." << endl;
      return Failure;
    }

    ifstream inFile(file_from,ios::in); //це об'єкт , який відповідає за читання даних з файлу, з якого ми копіюємо.
    if(!inFile){
      cerr << "Error: Unable to open source file: " << file_from << endl;
      return Failure;
    }
    ofstream outFile(file_to,ios::out);//це об'єкт , який відповідає за запис даних з файлу, з якого ми копіюємо.
    if(!outFile){
      cerr << "Error: Unable create source file: " << file_from << endl;
      inFile.close();
      return Failure;
    }

    string line;
    while (getline(inFile,line)){
      outFile << line << endl;
      if(!outFile.good()){
        cerr << "Error: Failed to write to destination file: " << file_to << endl;
        inFile.close();
        outFile.close();
        return Failure;
      }
    }

    inFile.close();
    outFile.close();
    
    return Success;
  }

  int main (){
    const char* fileName = "test.txt";
    const char* fileCopy = "test_copy.txt";
    char content[256];

    cout << "Enter content to write to the file: ";
    cin.getline(content, sizeof(content));

    FileOrResult result = write_to_file(fileName,content);
    if (result == Success) {
      cout << "File successfully written to " << fileName << endl;
    } else {
      cout << "Failed to write to file: " << fileName << endl;
    }

    result = copy_file (fileName,fileCopy);
    if(result == Success){
      cout << "File successfully copied to " << fileCopy << endl;
    } else{
      cout << "Failed to copy file to " << fileCopy << endl;
    }

    return 0;
  }