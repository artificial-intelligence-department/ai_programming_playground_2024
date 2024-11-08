#include <iostream>
#include <cstdio> 

using namespace std;

int main() {

    float n_f, m_f;
    double n_d, m_d;

    printf("Enter n and m (float): ");
    scanf("%f %f", &n_f, &m_f);

    printf("Enter n and m (double): ");
    scanf("%lf %lf", &n_d, &m_d);

    float result1_f = ++n_f * ++m_f;
    bool result2_f = m_f++ < n_f;
    bool result3_f = n_f++ > m_f;

    double result1_d = ++n_d * ++m_d;
    bool result2_d = m_d++ < n_d;
    bool result3_d = n_d++ > m_d;

    printf("Result for float:\n");
    printf("++n * ++m: %.2f\n", result1_f);
    printf("m++ < n: %s\n", result2_f ? "true" : "false");
    printf("n++ > m: %s\n", result3_f ? "true" : "false");

    printf("Result for double:\n");
    printf("++n * ++m: %.2lf\n", result1_d);
    printf("m++ < n: %s\n", result2_d ? "true" : "false");
    printf("n++ > m: %s\n", result3_d ? "true" : "false");

    return 0;
}
