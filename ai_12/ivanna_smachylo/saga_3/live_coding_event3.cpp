#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctime>    
#include <string>   

using namespace std;

int vowels()
{
    char line[150];
    int vowels;

    vowels = 0;

    cout << "Enter a line of string: ";
    cin.getline(line, 150);
    for(int i = 0; line[i] != '\0'; i++)
    {
        if(line[i]=='a' || line[i]=='e' || line[i]=='i' ||
           line[i]=='o' || line[i]=='u' || line[i]=='A' ||
           line[i]=='E' || line[i]=='I' || line[i]=='O' ||
           line[i]=='U')
        {
            vowels++;
        }
    }
    cout << "Vowels: " << vowels << "\n";
    return vowels;
}

double** function_2(int &vow)
{
    string lastname = "Smachylo";
    int random;
    double** matrix = new double*[vow];
    cout << "Values of the matrix: ";
    srand (time(0));
    for (int i = 0; i < vow; i++)
    {
        matrix[i] = new double[vow];
        cout << rand() % 40+20 << "\n";
    }
    cout << "\n";

    for(int i = 0; i < vow; i = i + 2)
    {
        matrix[i] = new double[vow];
        cout << rand()% 40 + 20 << "\n";
    }

    for(int i = 0; i < vow; i++)
    {
        if(i < lastname.size())
        {
            matrix[i] = new double[vow];
            cout << lastname[i] << "\n";
        }
    }

    for(int i = 0; i < vow; i++)
    {
        for(int j = 0; j < vow; j++)
        {
            cout << matrix[i][j] << "\n";
        }
    }
    cout << "\n";

    return matrix;
}

double** function_3(int &vow)
{
    double** matrix = new double*[vow];
    for(int i = 0; i < vow; i++)
    {
        matrix[i] = new double[vow];
        for(int j = 0; j < vow; j++)
        {
            cout << matrix[i][j] << "\n";
        }
    }
    cout << "\n";
    return matrix;
}

int main()
{
    int vow = vowels();
    double** second = function_2(vow);
    double** third = function_3(vow);

    ifstream inFile("matrix.bin", ios::binary);
    if(inFile.is_open())
    {
        cout << "Matrix: " << "\n";
        second;
        third;
        inFile.seekg (0, inFile.end);
        int length = inFile.tellg();
        inFile.seekg (0, inFile.beg);

        char * buffer = new char [length];
        
        inFile.read (buffer,length);

        inFile.close();
    }

    return 0;
}