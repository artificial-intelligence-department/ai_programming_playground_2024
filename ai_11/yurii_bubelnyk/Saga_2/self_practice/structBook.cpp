#include <iostream>
#include <string>

using namespace std;

class Ball
{
private:
    string m_color;
    double m_radius;
public:
    Ball()
    {
        m_color = "red";
        m_radius = 20.0;
    }
    Ball(const string &m_color)
    {
        this->m_color = m_color;
        m_radius = 20.0;
    }
    Ball(double m_radius)
    {
        m_color = "red";
        this->m_radius = m_radius;
    }
    Ball(const string &color, double radius)
	{
		m_color = color;
		m_radius = radius;
	}
    void print()
	{
		cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
    Ball def;
    def.print();
    Ball black("balck");
    black.print();
    return 0;
}