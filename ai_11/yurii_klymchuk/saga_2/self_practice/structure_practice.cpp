#include <iostream>

using namespace std;

int counter = 0;

struct Question {
    string question;
    string options[3];
    bool answer[3];
};

void ProcessTheQuestion(Question question) {
    int user_answer;
    cout << question.question << endl;
    for (int i = 0; i < 3; i++) {
        cout << question.options[i] << endl;
    }
    cout << "Choose 1-3: ";
    cin >> user_answer;
    if (question.answer[user_answer - 1]) {
        cout << "Correct" << endl;
        counter++;
    } else {
        cout << "Incorrect" << endl; 
    }
};

int main() { 
    Question question_1;
    question_1.question = "The biggest number is:";
    question_1.options[0] = "1. 1/2";
    question_1.options[1] = "2. 7/13";
    question_1.options[2] = "3. 99/177";
    question_1.answer[0] = false;
    question_1.answer[1] = false;
    question_1.answer[2] = true;
    ProcessTheQuestion(question_1);

    Question question_2;
    question_2.question = "The founder of OUN";
    question_2.options[0] = "1. Miknowskiy";
    question_2.options[1] = "2. Melynuk";
    question_2.options[2] = "3. Konowaletz";
    question_2.answer[0] = false;
    question_2.answer[1] = false;
    question_2.answer[2] = true;
    ProcessTheQuestion(question_2);
    return 0;
}