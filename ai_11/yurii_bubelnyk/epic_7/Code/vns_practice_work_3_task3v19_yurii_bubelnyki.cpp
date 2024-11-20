#include <iostream>
#include <cmath> // підключив бібліотеку для abs()
#include <iomanip>  // Для встановлення точності виведення
#include <cstdio> // Для fopen, fprintf, fclose

using namespace std;

const int BUFFER = 256;

double Square(double x1, double y1, double x2, double y2, double x3, double y3);

bool IsValid(double x1, double y1, double x2, double y2, double x3, double y3);

double calculateValue(int numNotebooks, int numPencils, double priceNotebook, double pricePencil);

void CreateFile(const char* filename, double (*Func)(int, int, double, double), int numNotebooks, int numPencils, double priceNotebook, double pricePencil);

void ShowFile(const char* filename);

int main() {
    const char* filename = "Work3.txt";
    double x1, y1, x2, y2, x3, y3 = 0;

    do {
        cout << "x1,y1 > " << endl;
        cin >> x1 >> y1;
        cout << "x2,y2 > " << endl;
        cin >> x2 >> y2;
        cout << "x3,y3 > " << endl;
        cin >> x3 >> y3;

        // Перевіряємо, чи введено правильні координати
        if (IsValid(x1, y1, x2, y2, x3, y3)) {
            break; // Виходимо з циклу, якщо координати правильні
        } else {
            cout << "Invalid coordinates! Points cannot be the same or form a degenerate triangle. Please try again." << endl;
        }

    } while (true);  // Повторюється, поки користувач не введе коректні координати

    // Встановлюємо точність до двох знаків після коми
    cout << fixed << setprecision(2);  
    cout << "Area of the triangle: " << Square(x1, y1, x2, y2, x3, y3) << " sq.cm." << endl;

    // Введення даних для покупки
    int numNotebooks, numPencils;
    double priceNotebook, pricePencil;

    cout << "\nEnter number of notebooks: ";
    cin >> numNotebooks;
    cout << "Enter price per notebook: ";
    cin >> priceNotebook;

    cout << "Enter number of pencils: ";
    cin >> numPencils;
    cout << "Enter price per pencil: ";
    cin >> pricePencil;

    cout << "Total cost of purchase: " << calculateValue(numNotebooks, numPencils, priceNotebook, pricePencil) << " UAH.\n";
    int choice; // для запису вибору
    // options для користувача (-_0)
    do{
        cout << "Ente choice:\n\t 1)Create the file;\n\t 2)Show the file;\n\t 3)Exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            CreateFile(filename, calculateValue, numNotebooks, numPencils, priceNotebook, pricePencil);
            break;
        case 2:
                ShowFile(filename);
            break;
        case 3:
            cout << "Exit -_-" << endl;
            break;
        default:
            break;
        }
    } while (choice != 3);
    
    return 0;
}

double Square(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Обчислення площі трикутника через координати
    double square = 0;
    //  обчислюємо площу трикутника за допомогою координат за формулою площі через координати вершин.
    square = 0.5 * ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1));
    return abs(square);  // Повертаємо абсолютне значення площі
}

bool IsValid(double x1, double y1, double x2, double y2, double x3, double y3) {
    // Перевірка, чи всі точки різні, щоб утворити трикутник
    if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3)) {
        return false;  // Точки не можуть бути однаковими
    }
    // Перевірка на вироджений трикутник (сума двох сторін повинна бути більшою за третю)
    double side1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double side2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double side3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    if (side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2) {
        return false;  // Якщо три сторони не можуть утворити трикутник
    }

    return true;  // Координати правильні для утворення трикутника
}

double calculateValue(int numNotebooks, int numPencils, double priceNotebook, double pricePencil) {
    double sum = numNotebooks * priceNotebook + numPencils * pricePencil;
    return sum;
}
// передаємо у функцію CreateFile функція calculateValue як pointer
void CreateFile(const char* filename, double (*Func)(int, int, double, double), int numNotebooks, int numPencils, double priceNotebook, double pricePencil){
    FILE* file = fopen(filename, "w"); // Відкриваємо файл для запису
    if (file == nullptr) {
        cerr << "Error while opening th file: " << filename << endl;
        return;
    }

    int result = Func(numNotebooks, numPencils, priceNotebook, pricePencil);

    // Записуємо результат у файл
    fprintf(file, "The total value is: %d\n", result);

    fclose(file); // Закриваємо файл
    cout << "Result has been written to the file: " << filename << endl;
}
// вивід даних з фалу в термінал
void ShowFile(const char* filename){
    FILE* file = fopen(filename, "r"); // Відкриваємо файл для запису
    if (file == nullptr) {
        cerr << "Error while opening th file: " << filename << endl;
        return;
    }

    char buffer[BUFFER];
    cout << "From the file)))" << endl;
    while (fgets(buffer, BUFFER, file) != nullptr) {
        cout << buffer; // Виводимо зчитаний рядок
    }
    
    fclose(file);
}
