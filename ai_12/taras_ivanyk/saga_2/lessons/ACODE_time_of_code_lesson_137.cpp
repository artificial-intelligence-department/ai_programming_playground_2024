#include <iostream>
#include <array>
#include <chrono>

const int g_arrayElements = 10000;

class Timer{
private: 
    using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
	{
	}
	
	void reset()
	{
		m_beg = clock_t::now();
	}
	
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray(std::array<int, g_arrayElements> &array)
{
 	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
 
		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[smallestIndex]);
	}
}
 
int main()
{
	std::array<int, g_arrayElements> array;
	for (int i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;
 
	Timer t;
 
	sortArray(array);
 
	std::cout << "Time taken: " << t.elapsed() << '\n';
 
	return 0;
}