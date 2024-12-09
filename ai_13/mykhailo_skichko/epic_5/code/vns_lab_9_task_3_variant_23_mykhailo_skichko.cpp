#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split(const string &line)
{
	stringstream ss(line);
	vector<string> words;
	string word;
	while (ss >> word)
	{
		words.push_back(word);
	}
	return words;
}

bool hasTwoIdenticalWords(const string &line)
{
	vector<string> words = split(line);
	map<string, int> word_count;
	for (const auto &word : words)
	{
		word_count[word]++;
	}
	for (const auto &pair : word_count)
	{
		if (pair.second == 2)
		{
			return true;
		}
	}
	return false;
}

int wordWithMostA(const string &line)
{
	vector<string> words = split(line);
	int max_a_count = 0, word_index = -1;
	for (size_t i = 0; i < words.size(); ++i)
	{
		int count_a = count_if(words[i].begin(), words[i].end(), [](char c)
							   { return tolower(c) == 'a'; });
		if (count_a > max_a_count)
		{
			max_a_count = count_a;
			word_index = i + 1;
		}
	}
	return word_index;
}

int main()
{
	ofstream fileF1("F1.txt");
	vector<string> F1_content = {
		"Apple banana apple grape",
		"This line contains no duplicates",
		"Another apple banana apple here",
		"Duplicate words are present here here",
		"This line is unique",
		"Orange orange orange banana",
		"Here we have grape grape again",
		"No duplicates here either",
		"Repeating repeating repeating words",
		"Final line has nothing special"};

	for (const auto &line : F1_content)
	{
		fileF1 << line << endl;
	}
	fileF1.close();

	ifstream fileF1Read("F1.txt");
	ofstream fileF2("F2.txt");
	string line;

	while (getline(fileF1Read, line))
	{
		if (hasTwoIdenticalWords(line))
		{
			fileF2 << line << endl;
		}
	}
	fileF1Read.close();
	fileF2.close();

	ifstream fileF1ReadAgain("F1.txt");
	vector<int> max_A_word_indexes;
	while (getline(fileF1ReadAgain, line))
	{
		max_A_word_indexes.push_back(wordWithMostA(line));
	}
	fileF1ReadAgain.close();

	cout << "File F1 has been created with the following content:\n";
	for (const auto &line : F1_content)
	{
		cout << line << endl;
	}
	cout << "\nRows with two identical words have been copied to F2.txt.\n";

	cout << "\nIndex of the word with the most 'A's in each line of F1:\n";
	for (int i = 0; i < max_A_word_indexes.size(); ++i)
	{
		cout << "Line " << i + 1 << ": " << max_A_word_indexes[i] << endl;
	}

	return 0;
}
