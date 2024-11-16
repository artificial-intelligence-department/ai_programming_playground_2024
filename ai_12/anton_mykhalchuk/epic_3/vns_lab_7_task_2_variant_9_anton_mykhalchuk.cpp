#include <iostream>
#include <utility>
using namespace std;

double DecimalAddition(double a, double b)
{
    return a + b;
}

float DecimalAddition(float a, float b)
{
    return a + b;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<int, int> fractionAddition(pair<int, int> f, pair<int, int> s)
{

    int numerator = f.first * s.second + s.first * f.second;
    int denominator = f.second * s.second;
    int d = gcd(numerator, denominator);
    numerator /= d;
    denominator /= d;

    return make_pair(numerator, denominator);
}

pair<long long, long long> fractionAddition(pair<long long, long long> f, pair<long long, long long> s)
{

    long long numerator = f.first * s.second + s.first * f.second;
    long long denominator = f.second * s.second;
    long long d = gcd(numerator, denominator);
    numerator /= d;
    denominator /= d;

    return make_pair(numerator, denominator);
}

int main()
{
    double ad = 45.434, bd = 2234.345;
    float af = 45.434, bf = 2234.345;

    cout << DecimalAddition(ad, bd) << endl;
    cout << DecimalAddition(af, bf) << endl;

    pair<int, int> firstFraction(15, 4), secondFraction(23, 6);
    pair<int, int> result = fractionAddition(firstFraction, secondFraction);
    cout << result.first << "/" << result.second << endl;

    pair<long long, long long> firstFractionl(4036854775807, 46476546475), secondFractionl(2342342352453, 345675364446);
    pair<long long, long long> resultl = fractionAddition(firstFractionl, secondFractionl);
    cout << resultl.first << "/" << resultl.second << endl;
    return 0;
}