#include <iostream> 
#include <cmath> 

int main(void) 
{ 
    const int size1D = 10; 
    const int rows = 3; 
    const int cols = 3; 

    // Одновимірний масив для зберігання значень функції 
    double functionValues[size1D]; 

    // Двовимірний масив для зберігання значень x та y 
    double xyValues[rows][cols] = { {0} }; 
    int index = 0; 
    double x = -2.5; 

 
    // Використання циклу do-while для обчислення значень функції 
    do 
    { 
        double z = abs(x) + std::pow(x, 2); 
        double y = z * ((sin(std::pow(2 + x, 2))) / (2 + x)); 
        // Зберігаємо значення y у одновимірний масив 
        if (index < size1D) 
        { 
            functionValues[index] = y; 
        } 
        // Зберігаємо значення x та y у двовимірний масив (обмежено розміром rows x cols) 
        if (index < rows * cols) 
        { 
            xyValues[index / cols][index % cols] = y; 
        } 
        std::cout << "Function value in [" << x << "] is -> " << y << std::endl; 
        x += 0.5; 
        index++; 
    } while (x <= 2); 

    // Використання циклу while для виведення значень з одновимірного масиву 
    int i = 0; 
    while (i < size1D) 
    { 
        std::cout << "Value from 1D array [" << i << "] -> " << functionValues[i] << std::endl; 
        i++; 
    } 

 
    for (int row = 0; row < rows; row++) 
    { 
        for (int col = 0; col < cols; col++) 
        { 
            std::cout << "Value from 2D array [" << row << "][" << col << "] -> " << xyValues[row][col] << std::endl; 
        } 
    } 

    return 0; 
}

 