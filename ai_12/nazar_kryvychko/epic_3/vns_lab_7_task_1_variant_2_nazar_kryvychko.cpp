#include<iostream>
#include<cstdarg>

float mult(int size, ...)
{
    va_list arguments;
    float product = 1; 
    va_start(arguments, size);
    for (unsigned short i = 0; i < size; i++)
    {
        float element = (float) va_arg(arguments, double);
        product *= element;
    }
    va_end(arguments);
    return product;
}

int main(void)
{
    float s = mult(3, 1.0f, 2.0f, 183.0f);  
    float s1 = mult(7, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f); 
    float s2 = mult(11, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f,2.0f,2.0f,2.0f,2.0f); 
    std::cout << "Product of 3 -> " << s << std::endl;
    std::cout << "Product of 7 twos -> " << s1 << std::endl;
    std::cout << "Product of 11 twos -> " << s2 << std::endl;
    return 0;
}
