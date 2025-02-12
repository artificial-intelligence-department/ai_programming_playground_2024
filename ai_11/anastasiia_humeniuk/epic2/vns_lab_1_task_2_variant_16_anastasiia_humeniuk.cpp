#include <iostream>
#include <cstdio> 

using namespace std;

int main() {

    float n_f, m_f;
    double n_d, m_d;

    printf("Введіть значення для n_f і m_f (float): ");
    scanf("%f %f", &n_f, &m_f);

    printf("Введіть значення для n_d і m_d (double): ");
    scanf("%lf %lf", &n_d, &m_d);

    // Обчислення для float
    float result1_f = ++n_f * ++m_f;
    bool result2_f = m_f++ < n_f;
    bool result3_f = n_f++ > m_f;

    // Обчислення для double
    double result1_d = ++n_d * ++m_d;
    bool result2_d = m_d++ < n_d;
    bool result3_d = n_d++ > m_d;

    printf("Результати для float:\n");
    printf("++n * ++m: %.2f\n", result1_f);
    printf("m++ < n: %s\n", result2_f ? "true" : "false");
    printf("n++ > m: %s\n", result3_f ? "true" : "false");

    printf("Результати для double:\n");
    printf("++n * ++m: %.2lf\n", result1_d);
    printf("m++ < n: %s\n", result2_d ? "true" : "false");
    printf("n++ > m: %s\n", result3_d ? "true" : "false");

    return 0;
}
