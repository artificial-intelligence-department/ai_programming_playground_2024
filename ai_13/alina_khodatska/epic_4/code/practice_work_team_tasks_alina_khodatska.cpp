#include <iostream>
#include <string>
using namespace std;

//���������� ������� ��� ��������, �� � ����� ����������
bool isPalindrome(const string& str, int start, int end) {
    // ������� �������: ���� ������ start ����� ��� ������� end
    if (start >= end) {
        return true;
    }

    // ���� ������� �� ������� � � ���� �� ����������
    if (str[start] != str[end]) {
        return false;
    }

    // ���������� ���������� ������� �������
    return isPalindrome(str, start + 1, end - 1);
}

// ������� ��� ��������, �� � ����� ����������
bool isPalindrome(int num) {
    // ���� ����� ���������, ���� �� ���� ���� ����������
    if (num < 0) return false;

    // ������������ ����� � ����� � ��������� ������� ��� �����
    string str = to_string(num);
    return isPalindrome(str, 0, str.size() - 1);
}

int main() {
    // ������� �������� ��� �����
    string word = "radar";
    if (isPalindrome(word, 0, word.size() - 1)) {
        cout << word << " is a palindrome!" << endl;
    }
    else {
        cout << word << " is not a palindrome!" << endl;
    }

    // ������� �������� ��� �����
    int number = 12321;
    if (isPalindrome(number)) {
        cout << number << " is a palindrome!" << endl;
    }
    else {
        cout << number << " is not a palindrome!" << endl;
    }

    return 0;
}
