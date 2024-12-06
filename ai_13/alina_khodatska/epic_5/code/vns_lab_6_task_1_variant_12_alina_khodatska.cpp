#include <iostream>
#include <cstring>  // ��� ������ � ��������
#include <algorithm>  // ��� ����������

using namespace std;

// ������� ��� ���������� ������� � ����
void sortWord(char* word) {
    int length = strlen(word);
    sort(word, word + length);  // ������� ������� � ����
}

int main() {
    char str[256]; // ������� �����, ����������� ������� 255 ������� + 1 ��� '\0'

    // ������� �����
    cout << "Enter a string: (max length 255 characters)" << endl;
    fgets(str, sizeof(str), stdin); 

    // ��������� ������ ������ ������ �����, ���� �� �
    size_t str_len = strlen(str);  // ���������� ������� ����� ���� ���
	if (str_len > 0 && str[str_len - 1] == '\n') { 
		str[str_len - 1] = '\0'; 
    }

    int i = 0;
    char word[256];  // ����� ��� ������ �����
    int wordIndex = 0;

    bool firstWord = true;  // ��� ���������� ��������� ������

	while (i <= str_len) { // ���� �� ��� �������� �����
        if (str[i] != ' ' && str[i] != '\0') {
            // ������� ������� �����
            word[wordIndex++] = str[i];
        }
        else {
            // ���� ����� ��������, ������� ���� � ��������
            if (wordIndex > 0) {
                word[wordIndex] = '\0';
                sortWord(word);
                if (!firstWord) {
                    cout << " ";  // �������� ����� ����� ������ ������ ���� �������
                }
                cout << word;
                wordIndex = 0;  // ������� �����
                firstWord = false;  // ϳ��� ������� ����� ������� ������ � ��������
            }
        }
        i++;
    }
    cout << endl;
    return 0;
}

// ����������� fgets ������ gets ������� gets � ��������� � �����������(���� ��������� ������������ ������) 