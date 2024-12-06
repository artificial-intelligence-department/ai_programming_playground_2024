#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
#include <vector>

using namespace std;

size_t findShortestWordLength(const string& line) {
   size_t minLength = INT_MAX;
   size_t currentLength = 0;

   for (char ch : line) {
      if (ch == ' ' || ch == '\n') {
         if (currentLength > 0 && currentLength < minLength) {
            minLength = currentLength;
         }
         currentLength = 0;
      } else {
         currentLength++;
      }
   }

   if (currentLength > 0 && currentLength < minLength) {
      minLength = currentLength;
   }

   return minLength;
}

int main() {
   const string fileF1 = "F1.txt";
   const string fileF2 = "F2.txt";
   vector<string> lines = {
   "Welcome to the programming world.",
   "C++ is powerful programming language.",
   "Short.",
   "This line contains a very small word.",
   "Here is another example of a line.",
   "A quick brown fox jumps over the lazy dog.",
   "This line is bit longer for testing purposes.",
   "An example with mixed word lengths.",
   "Tiny.",
   "This is the last line of this test file."
};


   ofstream outFileF1(fileF1);  // створення файлу F1 і запис даних
   if (!outFileF1) {
      cerr << "Error creating file F1!" << endl;
      return 1;
   }
   for (const auto& line : lines) {
      outFileF1 << line << endl;
   }
   outFileF1.close();

   ifstream inFileF1(fileF1);
   if (!inFileF1) {
      cerr << "Error opening file F1 for reading!" << endl;
      return 1;
   }

   string line;
   size_t minWordLength = INT_MAX;
   int shortestLineNumber = -1;
   int currentLineNumber = 0;

   vector<string> fileContent;
   while (getline(inFileF1, line)) {
      fileContent.push_back(line);
      currentLineNumber++;

      size_t currentMinLength = findShortestWordLength(line);
      if (currentMinLength < minWordLength) {
         minWordLength = currentMinLength;
         shortestLineNumber = currentLineNumber;
      }
   }
   inFileF1.close();

   ofstream outFileF2(fileF2);  //створення файлу F2 і запис даних окрім РЯДКА З НАЙКОРОТШИМ СЛОВОМ
   if (!outFileF2) {
      cerr << "Error creating file F2!" << endl;
      return 1;
   }

   currentLineNumber = 0;
   for (const auto& line : fileContent) {
      currentLineNumber++;
      if (currentLineNumber != shortestLineNumber) {
         outFileF2 << line << endl;
      }
   }
   outFileF2.close();

   cout << "The line number with the shortest word is: " << shortestLineNumber << endl;

   return 0;
}
