#include <iostream>
using namespace std;
long fileSIZE(FILE *filename);
int main()
{
    int k = 0;
    FILE *fileStream = fopen("lab9_1", "r");
    FILE *fileStream2 = fopen("lab9_2", "w");
    if (!fileStream || !fileStream2)
    {
        cout << "There is an error in opening the file!" << endl;
        return 1;
    }
    const size_t SIZE = 100;
    char string[SIZE];
    while (fgets(string, SIZE, fileStream))
    {
        if (k % 2 == 0 || k == 0)
        {
            fputs(string, fileStream2);
        }
        k++;
    }
    long size1 = fileSIZE(fileStream);
    long size2 = fileSIZE(fileStream2);
    cout << "Operation with files is succesfully completed!" << endl;
    cout << "Number of rows in file 1: " << k << endl;
    cout << "Size of file 1: " << size1 << " bytes" << endl;
    cout << "Size of file 2: " << size2 << " bytes" << endl;
    fclose(fileStream);
    fclose(fileStream2);
}
long fileSIZE(FILE *filename)
{
    fseek(filename, 0, SEEK_END);
    long size = ftell(filename);
    fseek(filename, 0, SEEK_SET);
    return size;
}