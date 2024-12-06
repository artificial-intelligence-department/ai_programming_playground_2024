#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Videotape{
  string title;
  string director;
  int duration;
  double price;
};


bool isValidDouble(const string& s) {
  if (s.empty()) return false;
  char* end = nullptr;
  strtod(s.c_str(), &end);
  return end == s.c_str() + s.size();
}

void addVideotape (const string& filename){
  Videotape tape;
  cout << "Enter film name : ";
  cin.ignore();
  getline(cin,tape.title);

  cout << "Enter director name : ";
  getline(cin,tape.director);
  cout << "Enter duration in minutes: ";
  cin >> tape.duration;
  cout << "Enter price : ";
  cin >> tape.price;

  ofstream file (filename , ios::app);
  if(file){
    file << tape.title << '|' << tape.director << '|' << tape.duration << '|' << tape.price << endl;
    file.close();
    cout << "Videotape was added" << endl;
  } else {
    cerr << "Error with opening file";
  }
}

void printVideotapes (const string& filename){
  ifstream file(filename);

  if(file){
    string line;
    cout << "List of Videotapes: " << endl;

    while(getline(file,line)){
      if (line.empty()) continue;

      size_t position = 0;
      Videotape tape;

      position = line.find("|");
      if (position == string::npos) continue;
      tape.title = line.substr(0,position);
      line.erase(0,position+1);

      position = line.find("|");
      if (position == string::npos) continue;
      tape.director = line.substr(0,position);
      line.erase(0,position+1);

      position = line.find("|");
      if (position == string::npos) continue; 
      tape.duration = stoi(line.substr(0,position));
      line.erase(0,position+1);

      if (!isValidDouble(line)) {
        cerr << "Invalid price format. Skipping line: " << line << endl;
        continue;
      }

      tape.price = stod(line);

      cout << "Title: " << tape.title << "\n"
      << "Director: " << tape.director << "\n"
      << "Duration: " << tape.duration << " min\n"
      << "Price: " << tape.price << " UAH\n"
      << "----------------------------------" << endl;
    }
    file.close();
  } else {
    cerr << "Error with opening file for reading.";
  }
}

void deleteExpensiveTapes(const string& filename , double maxPrice){
  ifstream file(filename);
    if(!file){
      cerr << "Error with opening file";
      return;
    }

  vector<Videotape> tapes;
  string line;

  while(getline(file,line)){
    if (line.empty()) continue;

      size_t position = 0;
      Videotape tape;

      position = line.find("|");
      if (position == string::npos) continue;
      tape.title = line.substr(0,position); //стирає
      line.erase(0,position+1);

      position = line.find("|");
      if (position == string::npos) continue;
      tape.director = line.substr(0,position);
      line.erase(0,position+1);

      position = line.find("|");
      if (position == string::npos) continue;
      tape.duration = stoi(line.substr(0,position)); // перетворює текст на цифри
      line.erase(0,position+1);

      if (!isValidDouble(line)) {
        cerr << "Invalid price format. Skipping line: " << line << endl;
        continue;
      }

      tape.price = stod(line);

     if (tape.price <= maxPrice){
        tapes.push_back(tape);
    }
  }   
  file.close();
  
  ofstream overwritingFile (filename, ios::trunc);
  if(!overwritingFile){
    cerr << "Error with opening file";
    return;
  }

  for (size_t i = 0; i < tapes.size(); ++i) {
    overwritingFile << tapes[i].title << "|" << tapes[i].director << "|" << tapes[i].duration << "|" << tapes[i].price << endl;
  }

  overwritingFile.close();
  
  cout << "Videotapes priced higher than " << maxPrice << " UAH have been removed.";
}

void processVideotapes(const string& filename, double maxPrice) {
  deleteExpensiveTapes(filename, maxPrice);

  cout << "\nAdding three new videotapes:\n";
  for (int i = 0; i < 3; ++i) {
  cout << "\nEnter details for new videotape #" << (i + 1) << ":\n";
  addVideotape(filename);
 }
}

int main() {
 const string filename = "videotapes.txt";
 int choice;
 double maxPrice;

 do {
  cout << "\nMenu:\n";
  cout << "1. Add a videotape\n";
  cout << "2. Show all videotapes\n";
  cout << "3. Delete videotapes with price above a specified value and add three new ones\n";
  cout << "4. Exit\n";
  cout << "Your choice: ";
  cin >> choice;
  cin.ignore();

  switch (choice) {
   case 1:
    addVideotape(filename);
    break;

   case 2:
    printVideotapes(filename);
    break;

   case 3:
    cout << "Enter the maximum price to filter videotapes: ";
    cin >> maxPrice;
    processVideotapes(filename, maxPrice);
    break;

   case 4:
    cout << "Exiting the program..." << endl;
    break;

   default:
    cerr << "Invalid choice! Please try again." << endl;
  }
 } while (choice != 4);

 return 0;
}
