#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool has_dup(const string& s) {
    istringstream iss(s);
    map<string, int> wc;
    string w;
    while (iss >> w) {
        wc[w]++;
        if (wc[w] > 1) return true;
    }
    return false;
}

int max_a(const string& s) {
    istringstream iss(s);
    string w;
    int max_a = 0, pos = -1, cur = 0;
    while (iss >> w) {
        cur++;
        int cnt = 0;
        for (char c : w) {
            if (tolower(c) == 'a') cnt++;
        }
        if (cnt > max_a) {
            max_a = cnt;
            pos = cur;
        }
    }
    return pos;
}

int main() {
    string f1 = "F1.txt", f2 = "F2.txt";

    ofstream out(f1);
    if (!out) {
        cerr << "Error opening F1" << endl;
        return 1;
    }
    out << "This is a test line with two test words.\n";
    out << "Another line for verification.\n";
    out << "This line has no duplicate words.\n";
    out << "Here is a line with many words, many words here.\n";
    out << "This line contains the word aaaa many times.\n";
    out << "Just a meaningless line.\n";
    out << "This is another line with text.\n";
    out << "This line contains words words words.\n";
    out << "A single line.\n";
    out << "A line for testing word verification.\n";
    out.close();

    ifstream in(f1);
    ofstream out2(f2);
    if (!in || !out2) {
        cerr << "File error" << endl;
        return 1;
    }
    string line;
    while (getline(in, line)) {
        if (has_dup(line)) {
            out2 << line << endl;
        }
    }
    in.close();
    out2.close();

    in.open(f1);
    if (!in) {
        cerr << "Error opening F1" << endl;
        return 1;
    }

    int max_pos = -1, line_num = 0, cur_line = 0;
    while (getline(in, line)) {
        cur_line++;
        int pos = max_a(line);
        if (pos > max_pos) {
            max_pos = pos;
            line_num = cur_line;
        }
    }
    in.close();

    cout << "Line number with the word having the most 'A's: " << line_num << endl;

    return 0;
}
